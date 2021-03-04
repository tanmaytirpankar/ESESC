#ifndef ESESCQEMUBM_H
#define ESESCQEMUBM_H

uint64_t QEMUReader_get_time(void);
uint32_t QEMUReader_cpu_start(uint32_t cpuid);
uint32_t QEMUReader_cpu_stop(uint32_t cpuid);
uint32_t QEMUReader_getFid(uint32_t last_fid); //FIXME: use FlowID instead of unint32_t
int32_t QEMUReader_setnoStats(uint32_t fid);

///MnB:~ Memory Data
uint64_t QEMUReader_queue_inst(uint64_t pc, uint64_t addr, uint16_t fid, uint16_t op, uint16_t src1, uint16_t src2, uint16_t dest, void *env);
//uint64_t QEMUReader_queue_inst(uint64_t pc, uint64_t addr, uint16_t fid, uint16_t op, uint16_t src1, uint16_t src2, uint16_t dest, void *env, void *oldData, void *newData);
///:.

void QEMUReader_syscall(uint32_t num, uint64_t usecs, uint32_t fid);
void QEMUReader_finish(uint32_t fid);
void QEMUReader_finish_thread(uint32_t fid);
uint32_t QEMUReader_resumeThread(uint32_t fid, uint32_t last_fid);
void QEMUReader_pauseThread(uint32_t fid);
void QEMUReader_start_roi(uint32_t fid);

void esesc_set_rabbit(uint32_t fid);
void esesc_set_warmup(uint32_t fid);
void esesc_set_timing(uint32_t fid);

#endif
