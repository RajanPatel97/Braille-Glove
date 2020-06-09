#include "spinlock.h"

inline uint8_t spin_trylock(spinlock_t *lock)
{
	if (nrf_atomic_u32_add(lock, 1) != 1) {
		nrf_atomic_u32_sub(lock, 1);
		return 0;
	}
	return 1;
}

void spin_lock(spinlock_t *lock)
{
	while (!spin_trylock(lock));
}

void spin_unlock(spinlock_t *lock)
{
	if (*lock >= 1)
		nrf_atomic_u32_sub(lock, 1);
}
