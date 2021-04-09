/* BOP [https://hal.inria.fr/hal-01254863/document] */

// #include "cache.h"
// #include <bits/stdc++.h>
#include <vector>
#include <string>
#include <iostream>
#include <iomanip>  // For setw
#include <map>


using namespace std;

class Table {
  public:
    Table(int width, int height) : width(width), height(height), cells(height, vector<string>(width)) {}

    void set_row(int row, const vector<string> &data, int start_col = 0) {
        assert(data.size() + start_col == this->width);
        for (unsigned col = start_col; col < this->width; col += 1)
            this->set_cell(row, col, data[col]);
    }

    void set_col(int col, const vector<string> &data, int start_row = 0) {
        assert(data.size() + start_row == this->height);
        for (unsigned row = start_row; row < this->height; row += 1)
            this->set_cell(row, col, data[row]);
    }

    void set_cell(int row, int col, string data) {
        assert(0 <= row && row < (int)this->height);
        assert(0 <= col && col < (int)this->width);
        this->cells[row][col] = data;
    }

    void set_cell(int row, int col, double data) {
        this->oss.str("");
        this->oss << setw(11) << fixed << setprecision(8) << data;
        this->set_cell(row, col, this->oss.str());
    }

    void set_cell(int row, int col, int64_t data) {
        this->oss.str("");
        this->oss << setw(11) << std::left << data;
        this->set_cell(row, col, this->oss.str());
    }

    void set_cell(int row, int col, int data) { this->set_cell(row, col, (int64_t)data); }

    void set_cell(int row, int col, uint64_t data) { this->set_cell(row, col, (int64_t)data); }

    string to_string() {
        vector<int> widths;
        for (unsigned i = 0; i < this->width; i += 1) {
            int max_width = 0;
            for (unsigned j = 0; j < this->height; j += 1)
                max_width = max(max_width, (int)this->cells[j][i].size());
            widths.push_back(max_width + 2);
        }
        string out;
        out += Table::top_line(widths);
        out += this->data_row(0, widths);
        for (unsigned i = 1; i < this->height; i += 1) {
            out += Table::mid_line(widths);
            out += this->data_row(i, widths);
        }
        out += Table::bot_line(widths);
        return out;
    }

    string data_row(int row, const vector<int> &widths) {
        string out;
        for (unsigned i = 0; i < this->width; i += 1) {
            string data = this->cells[row][i];
            data.resize(widths[i] - 2, ' ');
            out += " | " + data;
        }
        out += " |\n";
        return out;
    }

    static string top_line(const vector<int> &widths) { return Table::line(widths, "┌", "┬", "┐"); }

    static string mid_line(const vector<int> &widths) { return Table::line(widths, "├", "┼", "┤"); }

    static string bot_line(const vector<int> &widths) { return Table::line(widths, "└", "┴", "┘"); }

    static string line(const vector<int> &widths, string left, string mid, string right) {
        string out = " " + left;
        for (unsigned i = 0; i < widths.size(); i += 1) {
            int w = widths[i];
            for (int j = 0; j < w; j += 1)
                out += "─";
            if (i != widths.size() - 1)
                out += mid;
            else
                out += right;
        }
        return out + "\n";
    }

  private:
    unsigned width;
    unsigned height;
    vector<vector<string> > cells;
    ostringstream oss;
};

template <class T> class InfiniteCache {
  public:
    class Entry {
      public:
        uint64_t key;
        uint64_t index;
        uint64_t tag;
        bool valid;
        T data;
    };

    Entry *erase(uint64_t key) {
        Entry *entry = this->find(key);
        if (!entry)
            return NULL;
        entry->valid = false;
        this->last_erased_entry = *entry;
        int num_erased = this->entries.erase(key);
        assert(num_erased == 1);
        return &this->last_erased_entry;
    }

    /**
     * @return The old state of the entry that was written to.
     */
    Entry insert(uint64_t key, const T &data) {
        Entry *entry = this->find(key);
        if (entry != NULL) {
            Entry old_entry = *entry;
            entry->data = data;
            return old_entry;
        }
        entries[key] = {key, 0, key, true, data};
        return {};
    }

    Entry *find(uint64_t key) {
        typename map<uint64_t, Entry>::iterator it = this->entries.find(key);
        if (it == this->entries.end())
            return NULL;
        Entry &entry = (*it).second;
        assert(entry.tag == key && entry.valid);
        return &entry;
    }

    /**
     * For debugging purposes.
     */
    // string log(vector<string> headers, function<void(Entry &, Table &, int)> write_data) {
    //     Table table(headers.size(), entries.size() + 1);
    //     table.set_row(0, headers);
    //     unsigned i = 0;
    //     for (auto &x : this->entries)
    //         write_data(x.second, table, ++i);
    //     return table.to_string();
    // }

    void set_debug_mode(bool enable) { this->debug = enable; }

  protected:
    Entry last_erased_entry;
    map<uint64_t, Entry> entries;
    bool debug = false;
};

template <class T> class SetAssociativeCache {
  public:
    class Entry {
      public:
        uint64_t key;
        uint64_t index;
        uint64_t tag;
        bool valid;
        T data;
    };

    SetAssociativeCache(int size, int num_ways)
        : size(size), num_ways(num_ways), num_sets(size / num_ways), entries(num_sets, vector<Entry>(num_ways)),
          cams(num_sets) {
        assert(size % num_ways == 0);
        for (int i = 0; i < num_sets; i += 1)
            for (int j = 0; j < num_ways; j += 1)
                entries[i][j].valid = false;
    }

    Entry *erase(uint64_t key) {
        Entry *entry = this->find(key);
        uint64_t index = key % this->num_sets;
        uint64_t tag = key / this->num_sets;
        map<uint64_t, int> &cam = cams[index];
        int num_erased = cam.erase(tag);
        if (entry)
            entry->valid = false;
        assert(entry ? num_erased == 1 : num_erased == 0);
        return entry;
    }

    /**
     * @return The old state of the entry that was written to.
     */
    Entry insert(uint64_t key, const T &data) {
        Entry *entry = this->find(key);
        if (entry != NULL) {
            Entry old_entry = *entry;
            entry->data = data;
            return old_entry;
        }
        uint64_t index = key % this->num_sets;
        uint64_t tag = key / this->num_sets;
        vector<Entry> &set = this->entries[index];
        int victim_way = -1;
        for (int i = 0; i < this->num_ways; i += 1)
            if (!set[i].valid) {
                victim_way = i;
                break;
            }
        if (victim_way == -1) {
            victim_way = this->select_victim(index);
        }
        Entry &victim = set[victim_way];
        Entry old_entry = victim;
        victim = {key, index, tag, true, data};
        map<uint64_t, int> &cam = cams[index];
        if (old_entry.valid) {
            int num_erased = cam.erase(old_entry.tag);
            assert(num_erased == 1);
        }
        cam[tag] = victim_way;
        return old_entry;
    }

    Entry *find(uint64_t key) {
        uint64_t index = key % this->num_sets;
        uint64_t tag = key / this->num_sets;
        map<uint64_t, int> &cam = cams[index];
        if (cam.find(tag) == cam.end())
            return NULL;
        int way = cam[tag];
        Entry &entry = this->entries[index][way];
        assert(entry.tag == tag && entry.valid);
        return &entry;
    }

    /**
     * For debugging purposes.
     */
    // string log(vector<string> headers, function<void(Entry &, Table &, int)> write_data) {
    //     vector<Entry> valid_entries = this->get_valid_entries();
    //     Table table(headers.size(), valid_entries.size() + 1);
    //     table.set_row(0, headers);
    //     for (unsigned i = 0; i < valid_entries.size(); i += 1)
    //         write_data(valid_entries[i], table, i + 1);
    //     return table.to_string();
    // }

    void set_debug_mode(bool enable) { this->debug = enable; }

  protected:
    /**
     * @return The way of the selected victim.
     */
    virtual int select_victim(uint64_t index) {
        /* random eviction policy if not overriden */
        return rand() % this->num_ways;
    }

    vector<Entry> get_valid_entries() {
        vector<Entry> valid_entries;
        for (int i = 0; i < num_sets; i += 1)
            for (int j = 0; j < num_ways; j += 1)
                if (entries[i][j].valid)
                    valid_entries.push_back(entries[i][j]);
        return valid_entries;
    }

    int size;
    int num_ways;
    int num_sets;
    vector<vector<Entry> > entries;
    vector<map<uint64_t, int> > cams;
    bool debug = false;
};

template <class T> class LRUSetAssociativeCache : public SetAssociativeCache<T> {
    typedef SetAssociativeCache<T> Super;

  public:
    LRUSetAssociativeCache(int size, int num_ways)
        : Super(size, num_ways), lru(this->num_sets, vector<uint64_t>(num_ways)) {}

    void set_mru(uint64_t key) { *this->get_lru(key) = this->t++; }

    void set_lru(uint64_t key) { *this->get_lru(key) = 0; }

  protected:
    /* @override */
    int select_victim(uint64_t index) {
        vector<uint64_t> &lru_set = this->lru[index];
        return min_element(lru_set.begin(), lru_set.end()) - lru_set.begin();
    }

    uint64_t *get_lru(uint64_t key) {
        uint64_t index = key % this->num_sets;
        uint64_t tag = key / this->num_sets;
        int way = this->cams[index][tag];
        return &this->lru[index][way];
    }

    vector<vector<uint64_t> > lru;
    uint64_t t = 0;
};

template <class T> class NMRUSetAssociativeCache : public SetAssociativeCache<T> {
    typedef SetAssociativeCache<T> Super;

  public:
    NMRUSetAssociativeCache(int size, int num_ways) : Super(size, num_ways), mru(this->num_sets) {}

    void set_mru(uint64_t key) {
        uint64_t index = key % this->num_sets;
        uint64_t tag = key / this->num_sets;
        int way = this->cams[index][tag];
        this->mru[index] = way;
    }

  protected:
    /* @override */
    int select_victim(uint64_t index) {
        int way = rand() % (this->num_ways - 1);
        if (way >= mru[index])
            way += 1;
        return way;
    }

    vector<int> mru;
};

template <class T> class LRUFullyAssociativeCache : public LRUSetAssociativeCache<T> {
    typedef LRUSetAssociativeCache<T> Super;

  public:
    LRUFullyAssociativeCache(int size) : Super(size, size) {}
};

template <class T> class NMRUFullyAssociativeCache : public NMRUSetAssociativeCache<T> {
    typedef NMRUSetAssociativeCache<T> Super;

  public:
    NMRUFullyAssociativeCache(int size) : Super(size, size) {}
};

template <class T> class DirectMappedCache : public SetAssociativeCache<T> {
    typedef SetAssociativeCache<T> Super;

  public:
    DirectMappedCache(int size) : Super(size, 1) {}
};

/** End Of Cache Framework **/

class RecentRequestsTableData {
  public:
    uint64_t base_address;
};

class RecentRequestsTable : public DirectMappedCache<RecentRequestsTableData> {
    typedef DirectMappedCache<RecentRequestsTableData> Super;

  public:
    RecentRequestsTable(int size) : Super(size) {
        assert(__builtin_popcount(size) == 1);
        this->hash_w = __builtin_ctz(size);
    }

    Entry insert(uint64_t base_address) {
        uint64_t key = this->hash(base_address);
        return Super::insert(key, {base_address});
    }

    bool find(uint64_t base_address) {
        uint64_t key = this->hash(base_address);
        return (Super::find(key) != NULL);
    }

    // Gives "error: invalid conversion from 'char' to 'const char*'" that I can't fix
    // string log() {
    //     vector<string> headers({"Hash", "Base Address"});
    //     return Super::log(headers, this->write_data);
    // }

  private:
    static void write_data(Entry &entry, Table &table, int row) {
        table.set_cell(row, 0, bitset<20>(entry.key).to_string());
        table.set_cell(row, 1, entry.data.base_address);
    }

    /* The RR table is accessed through a simple hash function. For instance, for a 256-entry RR table, we XOR the 8
     * least significant line address bits with the next 8 bits to obtain the table index. For 12-bit tags, we skip the
     * 8 least significant line address bits and extract the next 12 bits. */
    uint64_t hash(uint64_t input) {
        int next_w_bits = ((1 << hash_w) - 1) & (input >> hash_w);
        uint64_t output = ((1 << 20) - 1) & (next_w_bits ^ input);
        if (this->debug) {
            cerr << "[RR] hash( " << bitset<32>(input).to_string() << " ) = " << bitset<20>(output).to_string() << endl;
        }
        return output;
    }

    int hash_w;
};

class BestOffsetLearning {
  public:
    BestOffsetLearning(int blocks_in_page) : blocks_in_page(blocks_in_page) {
        /* Useful offset values depend on the memory page size, as the BO prefetcher does not prefetch across page
         * boundaries. For instance, assuming 4KB pages and 64B lines, a page contains 64 lines, and there is no point
         * in considering offset values greater than 63. However, it may be useful to consider offsets greater than 63
         * for systems having superpages. */
        /* We propose a method for offset sampling that is algorithmic and not totally arbitrary: we include in our list
         * all the offsets between 1 and 256 whose prime factorization does not contain primes greater than 5. */
        /* Nothing prevents a BO prefetcher to use negative offset values. Although some applications might benefit from
         * negative offsets, we did not observe any benefit in our experiments. Hence we consider only positive offsets
         * in this study. */
        for (int i = 1; i < blocks_in_page; i += 1) {
            int n = i;
            for (int j = 2; j <= 5; j += 1)
                while (n % j == 0)
                    n /= j;
            if (n == 1)
                offset_list.push_back({i, 0});
        }
    }

    /**
     * @return The current best offset.
     */
    int test_offset(uint64_t block_number, RecentRequestsTable &recent_requests_table) {
        int page_offset = block_number % this->blocks_in_page;
        Entry &entry = this->offset_list[this->index_to_test];
        bool found =
            is_inside_page(page_offset - entry.offset) && recent_requests_table.find(block_number - entry.offset);
        if (this->debug) {
            cerr << "[BOL] testing offset=" << entry.offset << " with score=" << entry.score << endl;
            cerr << "[BOL] match=" << found << endl;
        }
        if (found) {
            entry.score += 1;
            if (entry.score > this->best_score) {
                this->best_score = entry.score;
                this->local_best_offset = entry.offset;
            }
        }
        this->index_to_test = (this->index_to_test + 1) % this->offset_list.size();
        /* test round termination */
        if (this->index_to_test == 0) {
            if (this->debug) {
                cerr << "[BOL] round=" << this->round << " finished" << endl;
            }
            this->round += 1;
            /* The current learning phase finishes at the end of a round when either of the two following events happens
             * first: one of the scores equals SCOREMAX, or the number of rounds equals ROUNDMAX (a fixed parameter). */
            if (this->best_score >= SCORE_MAX || this->round == ROUND_MAX) {
                if (this->best_score <= BAD_SCORE)
                    this->global_best_offset = 0; /* turn off prefetching */
                else
                    this->global_best_offset = this->local_best_offset;
                if (this->debug) {
                    cerr << "[BOL] learning phase finished, winner=" << this->global_best_offset << endl;
                    // cerr << this->log();
                }
                /* reset all internal state */
                //for (auto &entry : this->offset_list)
                //    entry.score = 0;
                for (int i=0; i < offset_list.size(); i++) {
                    Entry &entry = offset_list[i];
                    entry.score = 0;
                }
                this->local_best_offset = 0;
                this->best_score = 0;
                this->round = 0;
            }
        }
        return this->global_best_offset;
    }

    // string log() {
    //     Table table(2, offset_list.size() + 1);
    //     table.set_row(0, {"Offset", "Score"});
    //     for (unsigned i = 0; i < offset_list.size(); i += 1) {
    //         table.set_cell(i + 1, 0, offset_list[i].offset);
    //         table.set_cell(i + 1, 1, offset_list[i].score);
    //     }
    //     return table.to_string();
    // }

    void set_debug_mode(bool enable) { this->debug = enable; }

  private:
    bool is_inside_page(int page_offset) { return (0 <= page_offset && page_offset < this->blocks_in_page); }

    class Entry {
      public:
        int offset;
        int score;
    };

    int blocks_in_page;
    vector<Entry> offset_list;

    int round = 0;
    int best_score = 0;
    int index_to_test = 0;
    int local_best_offset = 0;
    int global_best_offset = 1;

    int SCORE_MAX = 31;
    int ROUND_MAX = 100;
    int BAD_SCORE = 1;

    bool debug = false;
};

class BOP {
  public:
    BOP(int blocks_in_page, int recent_requests_table_size, int degree)
        : blocks_in_page(blocks_in_page), best_offset_learning(blocks_in_page),
          recent_requests_table(recent_requests_table_size), degree(degree) {}

    /**
     * @return A vector of block numbers that should be prefetched.
     */
    vector<uint64_t> access(uint64_t block_number) {
        uint64_t page_number = block_number / this->blocks_in_page;
        int page_offset = block_number % this->blocks_in_page;
        /* ... and if X and X + D lie in the same memory page, a prefetch request for line X + D is sent to the L3
         * cache. */
        if (this->debug) {
            cerr << "[BOP] block_number=" << block_number << endl;
            cerr << "[BOP] page_number=" << page_number << endl;
            cerr << "[BOP] page_offset=" << page_offset << endl;
            cerr << "[BOP] best_offset=" << this->prefetch_offset << endl;
        }

        vector<uint64_t> pred;
        for (int i = 1; i <= this->degree; i += 1) {
            if (this->prefetch_offset != 0 && is_inside_page(page_offset + i * this->prefetch_offset))
                pred.push_back(block_number + i * this->prefetch_offset);
            else {
                if (this->debug)
                    cerr << "[BOP] X and X + " << i << " * D do not lie in the same memory page, no prefetch issued"
                         << endl;
                break;
            }
        }

        int old_offset = this->prefetch_offset;
        /* On every eligible L2 read access (miss or prefetched hit), we test an offset di from the list. */
        this->prefetch_offset = this->best_offset_learning.test_offset(block_number, recent_requests_table);
        if (this->debug) {
            if (old_offset != this->prefetch_offset)
                cerr << "[BOP] offset changed from " << old_offset << " to " << this->prefetch_offset << endl;
            //cerr << this->recent_requests_table.log();
            //cerr << this->best_offset_learning.log();
        }
        return pred;
    }

    void cache_fill(uint64_t block_number, bool prefetch) {
        int page_offset = block_number % this->blocks_in_page;
        if (this->prefetch_offset == 0 && prefetch)
            return;
        if (this->prefetch_offset != 0 && !prefetch)
            return;
        if (!this->is_inside_page(page_offset - this->prefetch_offset))
            return;
        this->recent_requests_table.insert(block_number - this->prefetch_offset);
    }

    void set_debug_level(int debug_level) {
        bool enable = (bool)debug_level;
        this->debug = enable;
        this->best_offset_learning.set_debug_mode(enable);
        this->recent_requests_table.set_debug_mode(enable);
    }

  private:
    bool is_inside_page(int page_offset) { return (0 <= page_offset && page_offset < this->blocks_in_page); }

    int blocks_in_page;
    int prefetch_offset = 0;

    BestOffsetLearning best_offset_learning;
    RecentRequestsTable recent_requests_table;
    int degree;

    bool debug = false;
};

// /* BOP settings */
const int RR_TABLE_SIZE = 256;
const int DEGREE = 1;
const int NUM_CPUS = 1; // FIXME: If multi-core
const int PAGE_SIZE = 32 * 64; // 32 blocks per page = 2048B
const int BLOCK_SIZE = 64;
const int LOG2_BLOCK_SIZE = 6;

vector<BOP> prefetchers;

void dram_prefetcher_initialize_(uint32_t cpu) {
    if (cpu != 0)
        return;

    /* create prefetcher for all cores */
    prefetchers = vector<BOP>(NUM_CPUS, BOP(PAGE_SIZE / BLOCK_SIZE, RR_TABLE_SIZE, DEGREE));
}

vector<uint64_t> dram_prefetcher_operate_(uint32_t cpu, uint64_t addr, uint64_t ip, uint8_t cache_hit, uint8_t type) {
    uint64_t block_number = addr >> LOG2_BLOCK_SIZE;
    // uint32_t set = get_set(block_number);
    // uint32_t way = get_way(block_number, set);
    // uint8_t prefetch = block[set][way].prefetch;    // I think this is supposed to be checking if it's a previous prefetch?

    /* check prefetch hit */
    // Can't check prefetch hit - not sure how to access it from DRAM using simulator?
    // bool prefetch_hit = false;
    // if (cache_hit == 1 && prefetch == 1)
    //     prefetch_hit = true;

    /* check trigger access */
    bool trigger_access = false;
    if (cache_hit == 0) // || prefetch_hit)
        trigger_access = true;

    if (!trigger_access)
        return vector<uint64_t>();  // Empty vector

    /* call prefetcher and send prefetches */
    vector<uint64_t> to_prefetch = prefetchers[cpu].access(block_number);
    for (int i = 0; i < to_prefetch.size(); i++) {
        to_prefetch[i] = to_prefetch[i] << LOG2_BLOCK_SIZE; // Convert back to addresses
    }
    // for (auto &pf_block_number : to_prefetch) {
    //    uint64_t pf_address = pf_block_number << LOG2_BLOCK_SIZE;
    //    /* champsim automatically ignores prefetches that cross page boundaries */
    //    prefetch_line(cpu, ip, addr, pf_address, FILL_LLC);
    //}
    return to_prefetch;
}

void dram_prefetcher_cache_fill_(
    uint32_t cpu, uint64_t addr, uint32_t set, uint32_t way, uint8_t prefetch, uint64_t evicted_addr) {
    prefetchers[cpu].cache_fill(addr >> LOG2_BLOCK_SIZE, (bool)prefetch);
}

// // void CACHE::llc_prefetcher_inform_warmup_complete_() {}

// // void CACHE::llc_prefetcher_inform_roi_complete_(uint32_t cpu) {}

// // void CACHE::llc_prefetcher_roi_stats_(uint32_t cpu) {}

// // void CACHE::llc_prefetcher_final_stats_(uint32_t cpu) {}