#ifndef _bb_spinlock_h
#define _bb_spinlock_h

#include <stdint.h>
#include <atomic/nrf_atomic.h>
typedef nrf_atomic_flag_t spinlock_t;

extern inline uint8_t spin_trylock(spinlock_t *lock);
extern void spin_lock(spinlock_t *lock);
extern inline void spin_unlock(spinlock_t *lock);

#endif // !defined(_bb_spinlock_h)
