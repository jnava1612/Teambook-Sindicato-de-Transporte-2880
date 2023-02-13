int ModPow(int a, int b, int m) {
  int res = 1;
  while (b > 0) {
    if (b & 1) res = (res * a) % m;
    a = (a * a) % m;
    b >>= 1;
  }
  return res;
}

// Language: java
public static int modPow(int a, int b, int m) {
  int res = 1;
  while (b > 0) {
    if ((b & 1) == 1) res = (res * a) % m;
    a = (a * a) % m;
    b >>= 1;
  }
  return res;
}

int ModInverse(int a, int m) {
  return ModPow(a, m - 2, m);
}