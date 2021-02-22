#pragma once

#define SquaredValue(a) (a * a)

#define LerpValue(a, b, t) (a + (t * (b - a)))

// TODO: Fix it so it works

#define MaxValue(a, b) ((a > b) ? a : b)

#define MinValue(a, b) ((a < b) ? a : b)

// c = 10
// a = 0
// b = 12

#define ClampValue(a, b, c) (MinValue(MaxValue(c, a), b))