#pragma once

#define SquaredValue(a) ((a) * (a))

#define LerpValue(a, b, t) ((a) + ((t) * ((b) - (a))))

#define MaxValue(a, b) (((a) > (b)) ? (a) : (b))

#define MinValue(a, b) (((a) < (b)) ? (a) : (b))

#define ClampValue(a, b, c) (MinValue(MaxValue(c, a), b))