#pragma once

#if defined(__SSE__) || defined(_M_X64) || defined(_M_IX86)

#include <xmmintrin.h> // SSE intrinsics

using SimdType = __m128;

inline SimdType SimdAdd(SimdType a, SimdType b) {
	return _mm_add_ps(a, b);
}

inline SimdType SimdSub(SimdType a, SimdType b) {
	return _mm_sub_ps(a, b);
}

inline SimdType SimdMul(SimdType a, SimdType b) {
	return _mm_mul_ps(a, b);
}

#elif defined(__ARM_NEON)

#include <arm_neon.h> // NEON intrinsics

using SimdType = float32x4_t;

inline SimdType SimdAdd(SimdType a, SimdType b) {
	return vaddq_f32(a, b);
}

inline SimdType SimdSub(SimdType a, SimdType b) {
	return vsubq_f32(a, b);
}

inline SimdType SimdMul(SimdType a, SimdType b) {
	return vmulq_f32(a, b);
}

#else
#error "Unsupported platform for SIMD operations"
#endif