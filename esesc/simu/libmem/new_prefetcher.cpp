#include <vector>
#include <string>
#include <iostream>
#include <iomanip>  // For setw
// #include <unordered_map> // ERROR: cannot include because requires c++11
#include <map>

using namespace std;


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
        // entries[key] = {key, 0, key, true, data};
        entries[key].key = key;
        entries[key].index = 0;
        entries[key].tag = key;
        entries[key].valid = true;
        entries[key].data = data;
        return Entry(); // {};
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
     * fromHunter: commenting then because giving an error that 'entries' not defined
     */
    // string log(vector<string> headers, function<void(Entry &, Table &, int)> write_data) {
    //     Table table(headers.size(), entries.size() + 1);
    //     table.set_row(0, headers);
    //     unsigned i = 0;
    //     for (auto &x : this->entries)
    //         write_data(x.second, table, ++i);
    //     return table.to_string();
    // }

    void set_debug_level(int debug_level) { this->debug_level = debug_level; }

  protected:
    Entry last_erased_entry;
    map<uint64_t, Entry> entries;
    int debug_level = 0;
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
        map<uint64_t, int> &cam = cams[index];   //fromHunter
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
        //victim = {key, index, tag, true, data};
        //fromHunter:
        victim.key = key;
        victim.index = index;
        victim.tag = tag;
        victim.valid = true;
        victim.data = data;
        map<uint64_t, int> &cam = cams[index];   //fromHunter
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
        map<uint64_t, int> &cam = cams[index];   //fromHunter
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
    //}

    void set_debug_level(int debug_level) { this->debug_level = debug_level; }

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
    int debug_level = 0;
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
    uint64_t t = 1;
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

class FilterTableData {
  public:
    uint64_t pc;
    int offset;
};

class FilterTable : public LRUFullyAssociativeCache<FilterTableData> {
    typedef LRUFullyAssociativeCache<FilterTableData> Super;

  public:
    FilterTable(int size) : Super(size) { assert(__builtin_popcount(size) == 1); }

    Entry *find(uint64_t region_number) {
        Entry *entry = Super::find(region_number);
        if (!entry)
            return NULL;
        this->set_mru(region_number);
        return entry;
    }

    void insert(uint64_t region_number, uint64_t pc, int offset) {
        assert(!this->find(region_number));
        Super::insert(region_number, {pc, offset});
        this->set_mru(region_number);
    }
};

class AccumulationTableData {
  public:
    uint64_t pc;
    int offset;
    vector<bool> pattern;
};

class AccumulationTable : public LRUFullyAssociativeCache<AccumulationTableData> {
    typedef LRUFullyAssociativeCache<AccumulationTableData> Super;

  public:
    AccumulationTable(int size, int pattern_len) : Super(size), pattern_len(pattern_len) {
        assert(__builtin_popcount(size) == 1);
        assert(__builtin_popcount(pattern_len) == 1);
    }

    /**
     * @return A return value of false means that the tag wasn't found in the table and true means success.
     */
    bool set_pattern(uint64_t region_number, int offset, bool print_out) {
        Entry *entry = Super::find(region_number);
        if (!entry) 
            return false;
        entry->data.pattern[offset] = true;
        this->set_mru(region_number);
        if (print_out) {
        	uint64_t pc = entry->data.pc;				/* use [pc_width] bits from pc */
        	uint64_t address = entry->key * 32 + entry->data.offset;	// Base address of the region
        	uint64_t offset = entry->data.offset;
        	printf("Found in accum table, pc: %lx, key: %lx, addr: %lx, offset: %d, pattern: ", pc, entry->key, address, offset);
        	for (int i = 0; i < 32; i++) {
        		if (entry->data.pattern[i] == false)
        			printf("0");
        		else
        			printf("1");
        	}
        	printf(".\n");
        }
        return true;
    }

    Entry insert(FilterTable::Entry &entry) {
        assert(!this->find(entry.key));
        vector<bool> pattern(this->pattern_len, false);
        pattern[entry.data.offset] = true;
        Entry old_entry = Super::insert(entry.key, {entry.data.pc, entry.data.offset, pattern});
        this->set_mru(entry.key);
        return old_entry;
    }

  private:
    int pattern_len;
};

template <class T> vector<T> my_rotate(const vector<T> &x, int n) {
    vector<T> y;
    int len = x.size();
    n = n % len;
    for (int i = 0; i < len; i += 1)
        y.push_back(x[(i - n + len) % len]);
    return y;
}

#define THRESH 0.20
#define USE_ONLY_PC_ADDR 1   // 0 = false, 1 = true, only use PC+Address

class PatternHistoryTableData {
  public:
    vector<bool> pattern;
};

class PatternHistoryTable : LRUSetAssociativeCache<PatternHistoryTableData> {
    typedef LRUSetAssociativeCache<PatternHistoryTableData> Super;

  public:
    PatternHistoryTable(
        int size, int pattern_len, int min_addr_width, int max_addr_width, int pc_width, int num_ways = 16)
        : Super(size, num_ways), pattern_len(pattern_len), min_addr_width(min_addr_width),
          max_addr_width(max_addr_width), pc_width(pc_width) {
        assert(this->pc_width >= 0);
        assert(this->min_addr_width >= 0);
        assert(this->max_addr_width >= 0);
        assert(this->max_addr_width >= this->min_addr_width);
        assert(this->pc_width + this->min_addr_width > 0);
        assert(__builtin_popcount(pattern_len) == 1);
        this->index_len = __builtin_ctz(this->num_sets);
    }

    /* address is actually block number */
    void insert(uint64_t pc, uint64_t address, vector<bool> pattern) {
        assert((int)pattern.size() == this->pattern_len);
        int offset = address % this->pattern_len;
        pattern = my_rotate(pattern, -offset);
        uint64_t key = this->build_key(pc, address);
        Super::insert(key, {pattern});
        this->set_mru(key);
    }

    /**
     * @return An un-rotated pattern if match was found, otherwise an empty vector.
     * Finds best match and in case of ties, uses the MRU entry.
     */
    vector<bool> find(uint64_t pc, uint64_t address) {
        uint64_t key = this->build_key(pc, address);
        uint64_t index = key % this->num_sets;
        uint64_t tag = key / this->num_sets;
        vector<Entry> &set = this->entries[index];
        uint64_t min_tag_mask = (1 << (this->pc_width + this->min_addr_width - this->index_len)) - 1;
        uint64_t max_tag_mask = (1 << (this->pc_width + this->max_addr_width - this->index_len)) - 1;
        vector<vector<bool> > min_matches;
        vector<bool> pattern;
        for (int i = 0; i < this->num_ways; i += 1) {
            if (!set[i].valid)
                continue;
            bool min_match = ((set[i].tag & min_tag_mask) == (tag & min_tag_mask));
            bool max_match = ((set[i].tag & max_tag_mask) == (tag & max_tag_mask));
            vector<bool> &cur_pattern = set[i].data.pattern;
            if (max_match) {
                this->set_mru(set[i].key);
                pattern = cur_pattern;
                break;
            }
            if (min_match) {
                min_matches.push_back(cur_pattern);
            }
        }
        if (pattern.empty()) {
            if (USE_ONLY_PC_ADDR == 0) {    //fromHunter, so we can turn off checking for a PC+Offset
                /* no max match was found, time for a vote! */
                pattern = this->vote(min_matches);
            } else {
                vector<bool> ret(this->pattern_len, false); //fromHunter, return empty vector of bools
                return ret;
            }
        }
        int offset = address % this->pattern_len;
        pattern = my_rotate(pattern, +offset);
        return pattern;
    }

  private:
    uint64_t build_key(uint64_t pc, uint64_t address) {
        pc &= (1 << this->pc_width) - 1;            /* use [pc_width] bits from pc */
        address &= (1 << this->max_addr_width) - 1; /* use [addr_width] bits from address */
        uint64_t offset = address & ((1 << this->min_addr_width) - 1);
        uint64_t base = (address >> this->min_addr_width);
        /* base + pc + offset */
        uint64_t key = (base << (this->pc_width + this->min_addr_width)) | (pc << this->min_addr_width) | offset;
        /* CRC */
        uint64_t tag = ((pc << this->min_addr_width) | offset);
        do {
            tag >>= this->index_len;
            key ^= tag & ((1 << this->index_len) - 1);
        } while (tag > 0);
        return key;
    }

    vector<bool> vote(const vector<vector<bool> > &x, float thresh = THRESH) {
        int n = x.size();
        vector<bool> ret(this->pattern_len, false);
        for (int i = 0; i < n; i += 1)
            assert((int)x[i].size() == this->pattern_len);
        for (int i = 0; i < this->pattern_len; i += 1) {
            int cnt = 0;
            for (int j = 0; j < n; j += 1)
                if (x[j][i])
                    cnt += 1;
            if (1.0 * cnt / n >= thresh)
                ret[i] = true;
        }
        return ret;
    }

    int pattern_len, index_len;
    int min_addr_width, max_addr_width, pc_width;
};


class Table_Entry {
  	public:
  		Table_Entry(int pattern_len) {
  			valid = false;
  			pc = 0;
  			address = 0;
  			lru = 0;
  			for (int i=0; i < pattern_len; i++) {
  			    pattern.push_back(false);
  			    confidences.push_back(0);
  			}
  		}
  		bool valid;
  		int lru;
  		uint64_t pc;
	    uint64_t address;
	    vector<bool> pattern;
	    vector<int> confidences;
};


class Bingo {
  public:
    Bingo(int pattern_len, int min_addr_width, int max_addr_width, int pc_width, int history_table_rows,
        int history_table_columns, int filter_table_size, int accumulation_table_size)
        : pattern_len(pattern_len), min_addr_width(min_addr_width), max_addr_width(max_addr_width), pc_width(pc_width),
          history_table_rows(history_table_rows), history_table_columns(history_table_columns), filter_table(filter_table_size), 
          accumulation_table(accumulation_table_size, pattern_len) 
        {
        	// Initialize the history table:
          	for (int i=0; i < history_table_rows; i++) {
		        vector<Table_Entry*> row;
		        for (int j=0; j < history_table_columns; j++) {
		            Table_Entry* entry = new Table_Entry(pattern_len);
		            row.push_back(entry);
		        }
		        table.push_back(row);
		    }
        }

    /**
     * @return A vector of block numbers that should be prefetched.
     */
    vector<uint64_t> access(uint64_t block_number, uint64_t pc) {
        if (this->debug_level >= 1) {
            cerr << "[Bingo] access(block_number=" << block_number << ", pc=" << pc << ")" << endl;
        }
        uint64_t region_number = block_number / this->pattern_len;
        int region_offset = block_number % this->pattern_len;

        bool print_out = false;
  		// if ((block_number >= 0x20740) && (block_number < 0x20760) && (pc == 0x120005528)) {
		// 	printf("Request for block: %lx in region %d with offset %d\t pc: %lx\n", block_number, region_number, region_offset, pc);
		// 	print_out = true;
		// }
        bool success = this->accumulation_table.set_pattern(region_number, region_offset, print_out);
        if (success) {
            // printf("Pushed to accumulation_table, block: %x is in region %x with offset %x\n", block_number, region_number, region_offset);
            return vector<uint64_t>();
        }
        FilterTable::Entry *entry = this->filter_table.find(region_number);
        if (!entry) {
            /* trigger access */
            // printf("Trigger access on block number: %x in region %x with offset %x\n", block_number, region_number, region_offset);
            this->filter_table.insert(region_number, pc, region_offset);
            // FIXME // vector<bool> pattern = this->find_in_phts(pc, block_number);
            vector<bool> pattern = find_in_hist_table(pc, block_number, false);
            if (pattern.empty())
                return vector<uint64_t>();
            vector<uint64_t> to_prefetch;
            for (int i = 0; i < this->pattern_len; i += 1)
                if (pattern[i])
                    to_prefetch.push_back(region_number * this->pattern_len + i);
            return to_prefetch;
        }
        if (entry->data.offset != region_offset) {
            /* move from filter table to accumulation table */
            // printf("Moving from filter to accum, block: %x is in region %x with offset %x\n", block_number, region_number, region_offset);
            AccumulationTable::Entry victim = this->accumulation_table.insert(*entry);
            this->accumulation_table.set_pattern(region_number, region_offset, false);
            this->filter_table.erase(region_number);
            if (victim.valid) {
                /* move from accumulation table to pattern history table */
                // FIXME // this->insert_in_phts(victim);
                //printf("MOVING %lx block into PHTS because it's overwritten\n", block_number);
                insert_in_hist_table(victim, false);
            }
        }
        return vector<uint64_t>();
    }

    void eviction(uint64_t block_number) {
        if (this->debug_level >= 1) {
            cerr << "[Bingo] eviction(block_number=" << block_number << ")" << endl;
        }
        /* end of generation */
        uint64_t region_number = block_number / this->pattern_len;
        this->filter_table.erase(region_number);
        AccumulationTable::Entry *entry = this->accumulation_table.erase(region_number);
        if (entry) {
            /* move from accumulation table to pattern history table */
            // FIXME // this->insert_in_phts(*entry);
            //uint64_t address = entry->key * this->pattern_len + entry->data.offset;
            //printf("MOVING %lx block of addr %lx into PHTS because page residency over\n", block_number, address);
            insert_in_hist_table(*entry, false);
        }
    }

  //   void set_debug_level(int debug_level) { this->debug_level = debug_level; }

  private:
  	vector<bool> find_in_hist_table(uint64_t pc, uint64_t address, bool print_out) {
  		pc &= (1 << pc_width) - 1;			/* use [pc_width] bits from pc */
  		address &= (1 << max_addr_width) - 1; /* use [addr_width] bits from address */
  		int offset = address & ((1 << min_addr_width) - 1);
  		int set = ((pc << min_addr_width) | offset) % history_table_rows;

  		int num_matches = 0;
  		int found_idx = -1;
  		vector<bool> pat(pattern_len, false);
  		vector<int> conf(pattern_len, 0);
  		for (int j = 0; j < history_table_columns; j++) {
  			if (table[set][j]->valid == true) {
  				if (table[set][j]->address == address) {
  					if (print_out) {
	  					printf("%lx == %lx and %lx == %lx, returning pattern: ", table[set][j]->pc, pc, table[set][j]->address, address);
	  					print_pattern(set, j);
	  				}
  					//return table[set][j]->pattern;
  					pat = table[set][j]->pattern;
  					conf = table[set][j]->confidences;
  					num_matches++;
  				}
  			}
  		}
  		if (num_matches > 1) 
  			printf("For pc: %lx, Addr: %lx, there were: %d matches.\n", pc, address, num_matches);

  		vector<bool> ret(pattern_len, false);
  		for (int i=0; i < pattern_len; i++) {
  			if (conf[i] > 0){	// TODO: Insert criteria here!
  				ret[i] = true;
  			}
  		}
  		return ret;	// Return empty vector if not found
  	}

  	int find_idx_in_hist_table(int set, uint64_t address){
  		for (int j = 0; j < history_table_columns; j++) {
  			if (table[set][j]->valid == true) {
  				if (table[set][j]->address == address) {
  					return j;
  				}
  			}
  		}
  		return -1;
  	}

  	void insert_in_hist_table(const AccumulationTable::Entry &entry, bool print_out) {
  		uint64_t pc = entry.data.pc;				
        uint64_t address = entry.key * pattern_len + entry.data.offset;	// Block Address (key is region number)
        pc &= (1 << pc_width) - 1;				/* use [pc_width] bits from pc */
        address &= (1 << max_addr_width) - 1; 	/* use [addr_width] bits from address */
        int offset = address & ((1 << min_addr_width) - 1);
        int set = ((pc << min_addr_width) | offset) % history_table_rows;

        const vector<bool> &pattern = entry.data.pattern;

        // if ((address >= 0x20740) && (address < 0x20760) && (pc == 0x5528)) {
        // 	print_out = true;
        // }

        int found_idx = find_idx_in_hist_table(set, address);
        if (found_idx == -1) {
	        int victim_idx = hist_table_get_lru(set);
	        table[set][victim_idx]->valid = true;
	        do_lru(set, victim_idx);
	        table[set][victim_idx]->pc = pc;
	        table[set][victim_idx]->address = address;
	        table[set][victim_idx]->pattern = pattern;
	        for (int i=0; i < pattern_len; i++) {
			    table[set][victim_idx]->confidences[i] = 0;
			}
			if (print_out) {
				printf("PC: %lx Addr: %lx stored in set %d idx %d with pattern: ", pc, address, set, victim_idx);
				print_pattern(set, victim_idx);
			}
		} else {
			if (print_out) {
				printf("Pattern before: ");
				print_pattern(set, found_idx);
				printf("Confdnc before: ");
				for (int i=0; i < pattern_len; i++) {
				    printf("%d", table[set][found_idx]->confidences[i]);
				}
				printf(".\n");
				printf("New pattern:    ");
				for (int i=0; i < pattern_len; i++) {
					if (pattern[i] == false)
				    	printf("0");
				    else
				    	printf("1");
				}
				printf(".\n");
			}
			// If the entry already exists, compare patterns to build up confidence
			vector<bool> old_pattern = table[set][found_idx]->pattern;
			for (int i=0; i < pattern_len; i++) {
				if (pattern[i] && old_pattern[i]) {
					table[set][found_idx]->confidences[i]++;	// Increase confidence
				} 
				else if (pattern[i] && !old_pattern[i]) {
					table[set][found_idx]->pattern[i] = 1;	// Confidence will be default to 0
				}
				else if (!pattern[i] && old_pattern[i]) {
					if (table[set][found_idx]->confidences[i] > 0)
						table[set][found_idx]->confidences[i]--;	// If confidence >0, decrement it
				}
			}
			if (print_out) {
				printf("Pattern after:  ");
				print_pattern(set, found_idx);
				printf("Confdnc after:  ");
				for (int i=0; i < pattern_len; i++) {
				    printf("%d", table[set][found_idx]->confidences[i]);
				}
				printf(".\n");
				printf("***************\n");
			}
		}
  	}

  	int hist_table_get_lru(int set) {
  		int min = 9999;
  		int idx = -1;
  		for (int j = 0; j < history_table_columns; j++) {
  			if (table[set][j]->valid == false) {
  				idx = j;	// If not valid, that's the lru, break early
  				break;
  			} else {
  				if (table[set][j]->lru < min) {
  					min = table[set][j]->lru;
  					idx = j;
  				}
  			}
  		}
  		if (idx != -1) {
  			return idx;
  		} else {
  			printf("ERROR: Minimum index for LRU not found, %d %d", min, idx);
  			exit(1);
  		}
  	}

  	void do_lru(int set, int idx) {
  		table[set][idx]->lru = history_table_columns;	// i.e. 16
  		for (int j = 0; j < history_table_columns; j++) {
  			table[set][j]->lru--;	// All get decremented
  		}
  	}

  	void print_pattern(int set, int idx) {
		for (int i=0; i < pattern_len; i++) {
		    if (table[set][idx]->pattern[i] == false)
		    	printf("0");
		    else
		    	printf("1");
		}
		printf(".\n");
  	}
  //   vector<bool> find_in_phts(uint64_t pc, uint64_t address) {
  //       if (this->debug_level >= 1) {
  //           cerr << "[Bingo] find_in_phts(pc=" << pc << ", address=" << address << ")" << endl;
  //       }
  //       return this->pht.find(pc, address);
  //   }

  //   void insert_in_phts(const AccumulationTable::Entry &entry) {
  //       if (this->debug_level >= 1) {
  //           cerr << "[Bingo] insert_in_phts(...)" << endl;
  //       }
  //       uint64_t pc = entry.data.pc;
  //       uint64_t address = entry.key * this->pattern_len + entry.data.offset;
  //       const vector<bool> &pattern = entry.data.pattern;
  //       this->pht.insert(pc, address, pattern);
  //   }

    int pattern_len;
    int min_addr_width;
    int max_addr_width;
    int pc_width;
    int history_table_rows;
    int history_table_columns;
    FilterTable filter_table;
    AccumulationTable accumulation_table;
    vector<vector<Table_Entry*> > table;
    int debug_level = 0;
};


const int REGION_SIZE = 2 * 1024;
const int LOG2_BLOCK_SIZE = 6;  // Assumes 64B cache block
const int PATTERN_LEN = REGION_SIZE >> LOG2_BLOCK_SIZE;		// 2048>>6 = 32
const int MIN_ADDR_WIDTH = 5;	// Basically log2(pattern_len)
const int MAX_ADDR_WIDTH = 16;	// Basically only use lower 16 bits of address
const int NUM_SETS = 1024;	// Make 1024?
const int NUM_ROWS = 16;		// Make 16?
const int PC_WIDTH = 16;	// Only use 16 bits
const int FT_SIZE = 64;
const int AT_SIZE = 128;
const int NUM_CPUS = 1; // FIXME: If multi-core

vector<Bingo> prefetchers;

void dram_prefetcher_initialize_(uint32_t cpu) {
	prefetchers = vector<Bingo>(NUM_CPUS, Bingo(PATTERN_LEN, MIN_ADDR_WIDTH, MAX_ADDR_WIDTH, PC_WIDTH, NUM_SETS, NUM_ROWS, FT_SIZE, AT_SIZE));
}

vector<uint64_t> dram_prefetcher_operate_(uint32_t cpu, uint64_t addr, uint64_t ip, uint8_t cache_hit, uint8_t type) {
	uint64_t block_number = addr >> LOG2_BLOCK_SIZE;
    vector<uint64_t> to_prefetch = prefetchers[cpu].access(block_number, ip);
    for (int i = 0; i < to_prefetch.size(); i++) {
        to_prefetch[i] = to_prefetch[i] << LOG2_BLOCK_SIZE; // Convert back to addresses
    }
    return to_prefetch;
}

void dram_prefetcher_cache_fill_(uint32_t cpu, uint64_t addr, uint32_t set, uint32_t way, uint8_t prefetch, uint64_t evicted_addr) {
    /* inform all Bingo modules of the eviction */
    for (int i = 0; i < NUM_CPUS; i += 1)
        prefetchers[i].eviction(evicted_addr >> LOG2_BLOCK_SIZE);
}