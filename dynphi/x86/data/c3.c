unsigned f0(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  if (!(((a & b) <= b))) r1 = 23u; else r1 = 158u;
  s += r1;
  if (((b * (b + 1u)) & 1u) == 0u) r0 = 169u; else r0 = 10u;
  s += r0;
  if (a < 20u) r2 = 83u; else r2 = 145u;
  s += r2;
  if (b < 22u) {
  i = 0u; do { i = i + 1u; s = s + i; } while (i < 6u);
  }
  if (b < 11u) {
  r0 = 1u; if (a < 17u) r0 = 2u; if (a < 17u) r0 = 9u;
  s += r0;
  }
  if (b < 5u) {
  r1 = 1u; if (b < 19u) r1 = 2u; if (b < 19u) r1 = 9u;
  s += r1;
  }
  return s;
}

unsigned f1(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  if (!(((a * (a + 1u)) & 1u) == 0u)) r2 = 35u; else r2 = 178u;
  s += r2;
  if (a == 4u) r2 = 193u; else r2 = 99u;
  s += r2;
  if (b < 13u) r3 = 32u; else r3 = 162u;
  s += r3;
  if (b < 20u) {
  r1 = 1u; if (b < 16u) r1 = 2u; if (b < 16u) r1 = 9u;
  s += r1;
  }
  return s;
}

unsigned f2(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  if (a < 6u) {
  if (a == 30u && b == 2u) r3 = 106u; else r3 = 94u;
  s += r3;
  }
  if (!(((a * (a + 1u)) & 1u) == 0u)) r0 = 95u; else r0 = 180u;
  s += r0;
  if (a == 28u && b == 13u) r2 = 147u; else r2 = 26u;
  s += r2;
  if (((b * (b + 1u)) & 1u) == 0u) r1 = 106u; else r1 = 59u;
  s += r1;
  if (a < 8u) r1 = 28u; else r1 = 199u;
  s += r1;
  if (a < 17u) r0 = 44u; else r0 = 156u;
  s += r0;
  return s;
}

unsigned f3(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  if (a == 15u) r0 = 175u; else r0 = 71u;
  s += r0;
  if (b < 17u) r2 = 23u; else r2 = 192u;
  s += r2;
  r2 = 1u; if (a < 8u) r2 = 2u; if (a < 8u) r2 = 9u;
  s += r2;
  if (b < 8u) r3 = 31u; else r3 = 108u;
  s += r3;
  if (b < 22u) {
  if (b < 24u) r3 = 24u; else r3 = 125u;
  s += r3;
  }
  if (a < 9u) {
  r1 = 1u; if (b < 19u) r1 = 2u; if (b < 19u) r1 = 9u;
  s += r1;
  }
  if (b < 9u) {
  if (a == 4u && b == 9u) r2 = 189u; else r2 = 83u;
  s += r2;
  }
  if (((b * b) & 3u) != 2u) r0 = 182u; else r0 = 14u;
  s += r0;
  return s;
}

unsigned f4(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  if (((a * (a + 1u)) & 1u) == 0u) r2 = 107u; else r2 = 4u;
  s += r2;
  if (a < 4u) {
  if (b < 21u) r2 = 20u; else r2 = 146u;
  s += r2;
  }
  r3 = 75u;
  s += r3;
  if (a < 22u) {
  i = 0u; do { i = i + 1u; s = s + i; } while (i < 6u);
  }
  r2 = 1u; if (b < 16u) r2 = 2u; if (b < 16u) r2 = 9u;
  s += r2;
  r2 = 1u; if (b < 12u) r2 = 2u; if (b < 12u) r2 = 9u;
  s += r2;
  if (a == 10u) r2 = 169u; else r2 = 52u;
  s += r2;
  return s;
}

unsigned f5(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  if (a < 11u) {
  if (((a | b) >= a)) r2 = 187u; else r2 = 38u;
  s += r2;
  }
  r3 = 1u; if (b < 9u) r3 = 2u; if (b < 9u) r3 = 9u;
  s += r3;
  if (!(((a & b) <= b))) r3 = 73u; else r3 = 110u;
  s += r3;
  if (a < 22u) r3 = 76u; else r3 = 198u;
  s += r3;
  r2 = 1u; if (b < 15u) r2 = 2u; if (b < 15u) r2 = 9u;
  s += r2;
  if (b < 21u) {
  r1 = 1u; if (b < 8u) r1 = 2u; if (b < 8u) r1 = 9u;
  s += r1;
  }
  return s;
}

unsigned f6(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  if (((b & a) <= a)) r1 = 163u; else r1 = 80u;
  s += r1;
  if (a < 24u) {
  if (a == 6u) r2 = 104u; else r2 = 93u;
  s += r2;
  }
  if (b < 19u) {
  r3 = 81u;
  s += r3;
  }
  r3 = 1u; if (b < 13u) r3 = 2u; if (b < 13u) r3 = 9u;
  s += r3;
  return s;
}

unsigned f7(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  r1 = 1u; if (a < 14u) r1 = 2u; if (a < 14u) r1 = 9u;
  s += r1;
  if (a < 26u) {
  if (a == 13u) r3 = 189u; else r3 = 80u;
  s += r3;
  }
  if (a < 12u) {
  if (b < 12u) r2 = 78u; else r2 = 149u;
  s += r2;
  }
  if (a == 23u && b == 4u) r0 = 130u; else r0 = 21u;
  s += r0;
  if (b < 22u) {
  if (a < 8u) r2 = 38u; else r2 = 183u;
  s += r2;
  }
  if (a == 2u) r3 = 100u; else r3 = 19u;
  s += r3;
  return s;
}

unsigned f8(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  if (!(((b | a) >= b))) r2 = 87u; else r2 = 148u;
  s += r2;
  if (b < 22u) {
  if (!(((a | b) >= a))) r0 = 49u; else r0 = 140u;
  s += r0;
  }
  r1 = 1u; if (b < 15u) r1 = 2u; if (b < 15u) r1 = 9u;
  s += r1;
  if (a < 16u) {
  if (a == 23u && b == 14u) r0 = 135u; else r0 = 42u;
  s += r0;
  }
  if (!(((a * (a + 1u)) & 1u) == 0u)) r1 = 28u; else r1 = 161u;
  s += r1;
  if (!(((b * (b + 1u)) & 1u) == 0u)) r3 = 35u; else r3 = 155u;
  s += r3;
  if (a < 12u) {
  i = 0u; do { i = i + 1u; s = s + i; } while (i < 2u);
  }
  if (a < 17u) r1 = 4u; else r1 = 173u;
  s += r1;
  return s;
}

unsigned f9(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  r1 = 1u; if (b < 22u) r1 = 2u; if (b < 22u) r1 = 9u;
  s += r1;
  if (a < 26u) {
  if (a == 21u) r0 = 144u; else r0 = 80u;
  s += r0;
  }
  i = 0u; do { i = i + 1u; s = s + i; } while (i < 3u);
  r1 = 77u;
  s += r1;
  if (b < 15u) {
  if (!(((b & a) <= a))) r2 = 54u; else r2 = 197u;
  s += r2;
  }
  if (b < 9u) {
  r1 = 1u; if (b < 15u) r1 = 2u; if (b < 15u) r1 = 9u;
  s += r1;
  }
  return s;
}

unsigned f10(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  r3 = 1u; if (a < 8u) r3 = 2u; if (a < 8u) r3 = 9u;
  s += r3;
  if (b < 7u) r2 = 33u; else r2 = 180u;
  s += r2;
  if (a < 26u) {
  if (a < 8u) r0 = 11u; else r0 = 129u;
  s += r0;
  }
  if (b < 10u) {
  r3 = 1u; if (a < 22u) r3 = 2u; if (a < 22u) r3 = 9u;
  s += r3;
  }
  return s;
}

unsigned f11(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  if (b < 26u) {
  i = 0u; do { i = i + 1u; s = s + i; } while (i < 2u);
  }
  if (b < 19u) {
  if (b < 16u) r3 = 59u; else r3 = 130u;
  s += r3;
  }
  if (a < 6u) {
  if (a == 13u && b == 2u) r2 = 170u; else r2 = 5u;
  s += r2;
  }
  if (((b & a) <= a)) r0 = 189u; else r0 = 2u;
  s += r0;
  if (b < 4u) {
  r3 = 1u; if (a < 12u) r3 = 2u; if (a < 12u) r3 = 9u;
  s += r3;
  }
  if (a < 18u) {
  if (b < 12u) r0 = 2u; else r0 = 162u;
  s += r0;
  }
  if (a < 11u) {
  if (!(((b | a) >= b))) r2 = 53u; else r2 = 132u;
  s += r2;
  }
  if (b < 12u) {
  if (((b & a) <= a)) r3 = 163u; else r3 = 91u;
  s += r3;
  }
  return s;
}

unsigned f12(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  if (b < 11u) {
  r3 = 1u; if (b < 20u) r3 = 2u; if (b < 20u) r3 = 9u;
  s += r3;
  }
  if (a < 14u) {
  if (!(((b * b) & 3u) != 2u)) r2 = 6u; else r2 = 181u;
  s += r2;
  }
  if (a < 9u) {
  if (((b * b) & 3u) != 2u) r3 = 136u; else r3 = 68u;
  s += r3;
  }
  if (b < 15u) {
  r0 = 71u;
  s += r0;
  }
  if (!(((a * a) & 3u) != 2u)) r3 = 15u; else r3 = 183u;
  s += r3;
  if (a == 11u && b == 6u) r0 = 139u; else r0 = 25u;
  s += r0;
  return s;
}

unsigned f13(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  if (a < 13u) {
  i = 0u; do { i = i + 1u; s = s + i; } while (i < 3u);
  }
  if (b < 19u) {
  if (!(((b * (b + 1u)) & 1u) == 0u)) r0 = 57u; else r0 = 146u;
  s += r0;
  }
  if (((a | b) >= a)) r1 = 141u; else r1 = 82u;
  s += r1;
  if (b < 24u) r1 = 42u; else r1 = 135u;
  s += r1;
  if (a < 18u) {
  if (a == 5u) r0 = 133u; else r0 = 1u;
  s += r0;
  }
  if (a < 24u) {
  if (!(((a & b) <= b))) r2 = 24u; else r2 = 102u;
  s += r2;
  }
  return s;
}

unsigned f14(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  if (b < 12u) {
  i = 0u; do { i = i + 1u; s = s + i; } while (i < 4u);
  }
  r1 = 1u; if (b < 8u) r1 = 2u; if (b < 8u) r1 = 9u;
  s += r1;
  if (a < 26u) {
  r3 = 1u; if (a < 15u) r3 = 2u; if (a < 15u) r3 = 9u;
  s += r3;
  }
  if (a < 14u) {
  r3 = 1u; if (b < 19u) r3 = 2u; if (b < 19u) r3 = 9u;
  s += r3;
  }
  r0 = 89u;
  s += r0;
  if (b < 20u) {
  if (a < 11u) r3 = 75u; else r3 = 140u;
  s += r3;
  }
  return s;
}

unsigned f15(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  if (!(((a * (a + 1u)) & 1u) == 0u)) r2 = 88u; else r2 = 134u;
  s += r2;
  r2 = 1u; if (a < 19u) r2 = 2u; if (a < 19u) r2 = 9u;
  s += r2;
  if (!(((a * a) & 3u) != 2u)) r0 = 89u; else r0 = 188u;
  s += r0;
  r2 = 1u; if (b < 18u) r2 = 2u; if (b < 18u) r2 = 9u;
  s += r2;
  return s;
}

unsigned f16(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  r2 = 1u; if (a < 12u) r2 = 2u; if (a < 12u) r2 = 9u;
  s += r2;
  if (a < 25u) {
  if (a == 26u && b == 15u) r0 = 190u; else r0 = 81u;
  s += r0;
  }
  if (((b * (b + 1u)) & 1u) == 0u) r1 = 190u; else r1 = 87u;
  s += r1;
  if (a < 19u) {
  if (((b | a) >= b)) r1 = 151u; else r1 = 24u;
  s += r1;
  }
  if (!(((a * a) & 3u) != 2u)) r2 = 4u; else r2 = 110u;
  s += r2;
  if (a < 18u) {
  if (((b * (b + 1u)) & 1u) == 0u) r3 = 181u; else r3 = 71u;
  s += r3;
  }
  r1 = 1u; if (b < 8u) r1 = 2u; if (b < 8u) r1 = 9u;
  s += r1;
  return s;
}

unsigned f17(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  r2 = 1u; if (a < 13u) r2 = 2u; if (a < 13u) r2 = 9u;
  s += r2;
  if (a < 5u) {
  if (a == 18u) r3 = 126u; else r3 = 77u;
  s += r3;
  }
  r2 = 1u; if (b < 21u) r2 = 2u; if (b < 21u) r2 = 9u;
  s += r2;
  if (b < 26u) {
  if (((a | b) >= a)) r2 = 156u; else r2 = 78u;
  s += r2;
  }
  if (a < 19u) r0 = 69u; else r0 = 108u;
  s += r0;
  if (a < 21u) {
  if (((a * a) & 3u) != 2u) r3 = 107u; else r3 = 21u;
  s += r3;
  }
  r1 = 1u; if (a < 10u) r1 = 2u; if (a < 10u) r1 = 9u;
  s += r1;
  if (((a | b) >= a)) r2 = 126u; else r2 = 14u;
  s += r2;
  return s;
}

unsigned f18(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  if (!(((b * b) & 3u) != 2u)) r0 = 71u; else r0 = 110u;
  s += r0;
  if (a < 18u) {
  if (!(((a | b) >= a))) r2 = 32u; else r2 = 146u;
  s += r2;
  }
  if (a < 24u) {
  if (((a | b) >= a)) r2 = 121u; else r2 = 96u;
  s += r2;
  }
  if (a < 16u) {
  if (a < 12u) r0 = 52u; else r0 = 147u;
  s += r0;
  }
  if (((a | b) >= a)) r1 = 170u; else r1 = 96u;
  s += r1;
  if (b < 26u) {
  if (((b | a) >= b)) r0 = 143u; else r0 = 38u;
  s += r0;
  }
  return s;
}

unsigned f19(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  r3 = 1u; if (a < 14u) r3 = 2u; if (a < 14u) r3 = 9u;
  s += r3;
  if (b < 14u) {
  if (!(((a * (a + 1u)) & 1u) == 0u)) r0 = 65u; else r0 = 110u;
  s += r0;
  }
  if (b < 23u) r2 = 56u; else r2 = 168u;
  s += r2;
  if (a == 28u) r0 = 169u; else r0 = 75u;
  s += r0;
  if (a < 25u) {
  i = 0u; do { i = i + 1u; s = s + i; } while (i < 6u);
  }
  if (a < 5u) {
  r1 = 1u; if (b < 16u) r1 = 2u; if (b < 16u) r1 = 9u;
  s += r1;
  }
  if (a < 9u) {
  if (a == 16u && b == 30u) r0 = 112u; else r0 = 23u;
  s += r0;
  }
  return s;
}

unsigned f20(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  if (b < 10u) {
  if (!(((b | a) >= b))) r1 = 99u; else r1 = 116u;
  s += r1;
  }
  r2 = 1u; if (b < 23u) r2 = 2u; if (b < 23u) r2 = 9u;
  s += r2;
  if (a < 18u) {
  if (!(((a * a) & 3u) != 2u)) r0 = 31u; else r0 = 141u;
  s += r0;
  }
  if (((b & a) <= a)) r1 = 180u; else r1 = 44u;
  s += r1;
  if (a < 27u) {
  if (a == 12u) r3 = 105u; else r3 = 9u;
  s += r3;
  }
  if (!(((a * (a + 1u)) & 1u) == 0u)) r3 = 9u; else r3 = 166u;
  s += r3;
  if (!(((a * (a + 1u)) & 1u) == 0u)) r1 = 92u; else r1 = 176u;
  s += r1;
  i = 0u; do { i = i + 1u; s = s + i; } while (i < 6u);
  return s;
}

unsigned f21(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  if (b < 7u) r2 = 46u; else r2 = 170u;
  s += r2;
  if (a == 3u) r3 = 163u; else r3 = 83u;
  s += r3;
  r3 = 1u; if (b < 23u) r3 = 2u; if (b < 23u) r3 = 9u;
  s += r3;
  if (b < 17u) {
  if (!(((a * a) & 3u) != 2u)) r0 = 45u; else r0 = 172u;
  s += r0;
  }
  return s;
}

unsigned f22(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  if (b < 9u) {
  r1 = 1u; if (b < 13u) r1 = 2u; if (b < 13u) r1 = 9u;
  s += r1;
  }
  i = 0u; do { i = i + 1u; s = s + i; } while (i < 2u);
  if (!(((a * (a + 1u)) & 1u) == 0u)) r1 = 57u; else r1 = 128u;
  s += r1;
  if (!(((a * (a + 1u)) & 1u) == 0u)) r3 = 71u; else r3 = 153u;
  s += r3;
  if (a == 11u && b == 11u) r3 = 166u; else r3 = 44u;
  s += r3;
  return s;
}

unsigned f23(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  if (a < 16u) {
  r0 = 86u;
  s += r0;
  }
  if (b < 11u) r3 = 29u; else r3 = 129u;
  s += r3;
  r2 = 1u; if (a < 17u) r2 = 2u; if (a < 17u) r2 = 9u;
  s += r2;
  r1 = 1u; if (a < 15u) r1 = 2u; if (a < 15u) r1 = 9u;
  s += r1;
  if (b < 16u) {
  if (a == 21u) r1 = 126u; else r1 = 89u;
  s += r1;
  }
  if (((b * (b + 1u)) & 1u) == 0u) r0 = 192u; else r0 = 83u;
  s += r0;
  if (b < 5u) {
  if (((a & b) <= b)) r2 = 112u; else r2 = 88u;
  s += r2;
  }
  if (!(((b & a) <= a))) r1 = 92u; else r1 = 172u;
  s += r1;
  return s;
}

unsigned f24(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  if (a < 8u) {
  if (!(((a * (a + 1u)) & 1u) == 0u)) r2 = 92u; else r2 = 168u;
  s += r2;
  }
  if (a < 20u) {
  if (a == 12u && b == 30u) r0 = 136u; else r0 = 87u;
  s += r0;
  }
  if (a < 9u) {
  if (b < 21u) r2 = 39u; else r2 = 151u;
  s += r2;
  }
  if (a < 8u) {
  if (((b * (b + 1u)) & 1u) == 0u) r2 = 119u; else r2 = 54u;
  s += r2;
  }
  return s;
}

unsigned f25(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  if (b < 19u) {
  r1 = 1u; if (a < 22u) r1 = 2u; if (a < 22u) r1 = 9u;
  s += r1;
  }
  r2 = 1u; if (b < 21u) r2 = 2u; if (b < 21u) r2 = 9u;
  s += r2;
  if (((a | b) >= a)) r2 = 129u; else r2 = 1u;
  s += r2;
  if (!(((b * b) & 3u) != 2u)) r3 = 29u; else r3 = 139u;
  s += r3;
  if (!(((a * a) & 3u) != 2u)) r2 = 26u; else r2 = 164u;
  s += r2;
  return s;
}

unsigned f26(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  r2 = 1u; if (b < 12u) r2 = 2u; if (b < 12u) r2 = 9u;
  s += r2;
  if (b < 12u) {
  if (!(((a & b) <= b))) r2 = 61u; else r2 = 168u;
  s += r2;
  }
  if (!(((a * a) & 3u) != 2u)) r0 = 72u; else r0 = 132u;
  s += r0;
  r3 = 1u; if (a < 23u) r3 = 2u; if (a < 23u) r3 = 9u;
  s += r3;
  if (b < 4u) {
  if (a == 5u && b == 4u) r2 = 150u; else r2 = 30u;
  s += r2;
  }
  if (!(((b * (b + 1u)) & 1u) == 0u)) r3 = 46u; else r3 = 168u;
  s += r3;
  return s;
}

unsigned f27(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  r0 = 1u; if (b < 8u) r0 = 2u; if (b < 8u) r0 = 9u;
  s += r0;
  if (((a | b) >= a)) r0 = 184u; else r0 = 93u;
  s += r0;
  if (a < 13u) r0 = 89u; else r0 = 144u;
  s += r0;
  if (b < 4u) {
  r2 = 1u; if (a < 11u) r2 = 2u; if (a < 11u) r2 = 9u;
  s += r2;
  }
  if (((b * (b + 1u)) & 1u) == 0u) r0 = 153u; else r0 = 4u;
  s += r0;
  r2 = 72u;
  s += r2;
  return s;
}

unsigned f28(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  if (a == 21u && b == 2u) r0 = 165u; else r0 = 73u;
  s += r0;
  if (!(((a | b) >= a))) r2 = 92u; else r2 = 169u;
  s += r2;
  if (a < 26u) {
  i = 0u; do { i = i + 1u; s = s + i; } while (i < 4u);
  }
  if (b < 6u) r3 = 59u; else r3 = 159u;
  s += r3;
  if (a < 13u) {
  if (!(((a * (a + 1u)) & 1u) == 0u)) r2 = 73u; else r2 = 104u;
  s += r2;
  }
  if (b < 25u) {
  if (!(((b * b) & 3u) != 2u)) r1 = 96u; else r1 = 185u;
  s += r1;
  }
  if (((a * (a + 1u)) & 1u) == 0u) r0 = 131u; else r0 = 28u;
  s += r0;
  return s;
}

unsigned f29(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  if (b < 24u) {
  r2 = 1u; if (b < 21u) r2 = 2u; if (b < 21u) r2 = 9u;
  s += r2;
  }
  if (((a * (a + 1u)) & 1u) == 0u) r1 = 147u; else r1 = 23u;
  s += r1;
  if (b < 22u) r0 = 16u; else r0 = 100u;
  s += r0;
  if (a < 17u) {
  r2 = 1u; if (a < 13u) r2 = 2u; if (a < 13u) r2 = 9u;
  s += r2;
  }
  if (b < 7u) {
  if (a == 22u && b == 5u) r0 = 108u; else r0 = 94u;
  s += r0;
  }
  if (a == 10u) r0 = 110u; else r0 = 51u;
  s += r0;
  r3 = 1u; if (b < 19u) r3 = 2u; if (b < 19u) r3 = 9u;
  s += r3;
  return s;
}

unsigned f30(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  r3 = 1u; if (b < 9u) r3 = 2u; if (b < 9u) r3 = 9u;
  s += r3;
  if (a < 21u) {
  if (a < 18u) r3 = 79u; else r3 = 128u;
  s += r3;
  }
  if (((a * a) & 3u) != 2u) r2 = 115u; else r2 = 1u;
  s += r2;
  if (a == 13u && b == 7u) r2 = 185u; else r2 = 75u;
  s += r2;
  if (b < 19u) {
  if (b < 15u) r0 = 88u; else r0 = 124u;
  s += r0;
  }
  if (b < 10u) {
  if (b < 11u) r3 = 49u; else r3 = 117u;
  s += r3;
  }
  return s;
}

unsigned f31(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  if (a < 21u) {
  if (((a | b) >= a)) r0 = 107u; else r0 = 13u;
  s += r0;
  }
  if (b < 17u) {
  if (((a & b) <= b)) r1 = 108u; else r1 = 48u;
  s += r1;
  }
  if (((a & b) <= b)) r3 = 116u; else r3 = 7u;
  s += r3;
  r3 = 1u; if (a < 15u) r3 = 2u; if (a < 15u) r3 = 9u;
  s += r3;
  if (b < 13u) r3 = 59u; else r3 = 188u;
  s += r3;
  if (b < 19u) {
  r3 = 1u; if (a < 17u) r3 = 2u; if (a < 17u) r3 = 9u;
  s += r3;
  }
  return s;
}

unsigned f32(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  r3 = 1u; if (a < 14u) r3 = 2u; if (a < 14u) r3 = 9u;
  s += r3;
  if (a < 25u) {
  i = 0u; do { i = i + 1u; s = s + i; } while (i < 2u);
  }
  if (a < 15u) {
  if (!(((a * (a + 1u)) & 1u) == 0u)) r2 = 81u; else r2 = 109u;
  s += r2;
  }
  if (a < 23u) {
  r2 = 58u;
  s += r2;
  }
  r1 = 1u; if (b < 18u) r1 = 2u; if (b < 18u) r1 = 9u;
  s += r1;
  if (b < 21u) r2 = 86u; else r2 = 187u;
  s += r2;
  if (b < 15u) {
  r1 = 1u; if (b < 18u) r1 = 2u; if (b < 18u) r1 = 9u;
  s += r1;
  }
  return s;
}

unsigned f33(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  if (b < 25u) r1 = 11u; else r1 = 153u;
  s += r1;
  if (a < 5u) {
  if (a == 23u && b == 1u) r2 = 113u; else r2 = 44u;
  s += r2;
  }
  if (a < 6u) {
  r3 = 1u; if (a < 13u) r3 = 2u; if (a < 13u) r3 = 9u;
  s += r3;
  }
  if (b < 12u) {
  r3 = 1u; if (b < 15u) r3 = 2u; if (b < 15u) r3 = 9u;
  s += r3;
  }
  if (a < 19u) r1 = 24u; else r1 = 112u;
  s += r1;
  if (b < 14u) r0 = 86u; else r0 = 174u;
  s += r0;
  return s;
}

unsigned f34(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  if (b < 13u) r0 = 45u; else r0 = 158u;
  s += r0;
  i = 0u; do { i = i + 1u; s = s + i; } while (i < 5u);
  i = 0u; do { i = i + 1u; s = s + i; } while (i < 2u);
  if (b < 25u) {
  r0 = 1u; if (a < 9u) r0 = 2u; if (a < 9u) r0 = 9u;
  s += r0;
  }
  if (b < 8u) r0 = 33u; else r0 = 174u;
  s += r0;
  return s;
}

unsigned f35(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  if (a < 12u) {
  i = 0u; do { i = i + 1u; s = s + i; } while (i < 4u);
  }
  if (b < 19u) {
  if (!(((b & a) <= a))) r0 = 42u; else r0 = 170u;
  s += r0;
  }
  if (((a | b) >= a)) r1 = 158u; else r1 = 96u;
  s += r1;
  if (b < 15u) {
  r1 = 1u; if (b < 9u) r1 = 2u; if (b < 9u) r1 = 9u;
  s += r1;
  }
  if (b < 10u) r2 = 51u; else r2 = 116u;
  s += r2;
  if (a < 23u) {
  if (a < 16u) r2 = 52u; else r2 = 132u;
  s += r2;
  }
  return s;
}

unsigned f36(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  if (((a | b) >= a)) r3 = 102u; else r3 = 62u;
  s += r3;
  if (a < 25u) {
  r0 = 1u; if (a < 13u) r0 = 2u; if (a < 13u) r0 = 9u;
  s += r0;
  }
  if (a == 19u && b == 18u) r0 = 173u; else r0 = 62u;
  s += r0;
  if (a < 15u) {
  r3 = 1u; if (a < 21u) r3 = 2u; if (a < 21u) r3 = 9u;
  s += r3;
  }
  r0 = 1u; if (a < 14u) r0 = 2u; if (a < 14u) r0 = 9u;
  s += r0;
  if (a < 8u) {
  i = 0u; do { i = i + 1u; s = s + i; } while (i < 5u);
  }
  if (b < 25u) {
  if (!(((a & b) <= b))) r1 = 20u; else r1 = 152u;
  s += r1;
  }
  i = 0u; do { i = i + 1u; s = s + i; } while (i < 6u);
  return s;
}

unsigned f37(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  if (a < 22u) {
  if (a == 28u && b == 25u) r0 = 101u; else r0 = 47u;
  s += r0;
  }
  if (b < 11u) {
  r3 = 92u;
  s += r3;
  }
  if (b < 8u) {
  if (!(((b * b) & 3u) != 2u)) r1 = 91u; else r1 = 148u;
  s += r1;
  }
  if (b < 19u) {
  r3 = 1u; if (a < 8u) r3 = 2u; if (a < 8u) r3 = 9u;
  s += r3;
  }
  r2 = 1u; if (b < 13u) r2 = 2u; if (b < 13u) r2 = 9u;
  s += r2;
  if (a < 19u) r0 = 2u; else r0 = 130u;
  s += r0;
  i = 0u; do { i = i + 1u; s = s + i; } while (i < 6u);
  r0 = 1u; if (a < 10u) r0 = 2u; if (a < 10u) r0 = 9u;
  s += r0;
  return s;
}

unsigned f38(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  if (b < 6u) {
  if (a == 6u) r0 = 150u; else r0 = 20u;
  s += r0;
  }
  if (!(((b * b) & 3u) != 2u)) r1 = 4u; else r1 = 134u;
  s += r1;
  if (b < 10u) {
  if (a < 18u) r1 = 63u; else r1 = 146u;
  s += r1;
  }
  if (a < 15u) r1 = 6u; else r1 = 139u;
  s += r1;
  return s;
}

unsigned f39(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  if (((b | a) >= b)) r3 = 143u; else r3 = 40u;
  s += r3;
  r1 = 33u;
  s += r1;
  if (a < 17u) {
  if (!(((a * (a + 1u)) & 1u) == 0u)) r1 = 48u; else r1 = 123u;
  s += r1;
  }
  if (b < 8u) r2 = 76u; else r2 = 146u;
  s += r2;
  if (b < 21u) r2 = 26u; else r2 = 178u;
  s += r2;
  return s;
}

unsigned f40(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  r1 = 3u;
  s += r1;
  i = 0u; do { i = i + 1u; s = s + i; } while (i < 6u);
  if (a < 19u) {
  if (!(((b & a) <= a))) r2 = 7u; else r2 = 122u;
  s += r2;
  }
  if (a == 17u) r2 = 103u; else r2 = 74u;
  s += r2;
  if (!(((a * a) & 3u) != 2u)) r1 = 31u; else r1 = 177u;
  s += r1;
  if (b < 4u) {
  r2 = 31u;
  s += r2;
  }
  return s;
}

unsigned f41(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  if (((b * (b + 1u)) & 1u) == 0u) r3 = 156u; else r3 = 99u;
  s += r3;
  if (a < 26u) {
  if (a == 14u && b == 25u) r2 = 124u; else r2 = 8u;
  s += r2;
  }
  r2 = 16u;
  s += r2;
  if (!(((b * (b + 1u)) & 1u) == 0u)) r0 = 41u; else r0 = 169u;
  s += r0;
  if (a < 9u) {
  if (a < 15u) r2 = 29u; else r2 = 113u;
  s += r2;
  }
  return s;
}

unsigned f42(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  if (!(((b * (b + 1u)) & 1u) == 0u)) r0 = 50u; else r0 = 133u;
  s += r0;
  if (b < 15u) {
  if (a < 9u) r0 = 96u; else r0 = 178u;
  s += r0;
  }
  if (b < 11u) {
  if (a == 6u && b == 23u) r3 = 103u; else r3 = 16u;
  s += r3;
  }
  if (((b & a) <= a)) r0 = 165u; else r0 = 83u;
  s += r0;
  if (b < 27u) {
  i = 0u; do { i = i + 1u; s = s + i; } while (i < 5u);
  }
  if (((b * (b + 1u)) & 1u) == 0u) r3 = 146u; else r3 = 96u;
  s += r3;
  return s;
}

unsigned f43(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  i = 0u; do { i = i + 1u; s = s + i; } while (i < 2u);
  if (!(((a * (a + 1u)) & 1u) == 0u)) r1 = 25u; else r1 = 113u;
  s += r1;
  if (b < 22u) {
  if (!(((b | a) >= b))) r1 = 11u; else r1 = 133u;
  s += r1;
  }
  if (a < 5u) {
  if (a == 5u && b == 30u) r0 = 162u; else r0 = 67u;
  s += r0;
  }
  r1 = 1u; if (a < 11u) r1 = 2u; if (a < 11u) r1 = 9u;
  s += r1;
  if (a < 27u) {
  if (((b | a) >= b)) r1 = 175u; else r1 = 1u;
  s += r1;
  }
  return s;
}

unsigned f44(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  if (a < 13u) {
  i = 0u; do { i = i + 1u; s = s + i; } while (i < 6u);
  }
  if (a == 27u) r1 = 177u; else r1 = 10u;
  s += r1;
  if (a == 24u) r1 = 168u; else r1 = 11u;
  s += r1;
  i = 0u; do { i = i + 1u; s = s + i; } while (i < 6u);
  if (a < 4u) {
  if (!(((b | a) >= b))) r2 = 17u; else r2 = 132u;
  s += r2;
  }
  if (b < 26u) {
  if (((b * b) & 3u) != 2u) r1 = 171u; else r1 = 70u;
  s += r1;
  }
  if (!(((a * (a + 1u)) & 1u) == 0u)) r1 = 47u; else r1 = 193u;
  s += r1;
  if (b < 15u) {
  if (b < 12u) r0 = 50u; else r0 = 104u;
  s += r0;
  }
  return s;
}

unsigned f45(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  if (!(((b * (b + 1u)) & 1u) == 0u)) r0 = 81u; else r0 = 189u;
  s += r0;
  if (!(((b * b) & 3u) != 2u)) r0 = 21u; else r0 = 178u;
  s += r0;
  r2 = 1u; if (b < 12u) r2 = 2u; if (b < 12u) r2 = 9u;
  s += r2;
  if (b < 10u) {
  if (a < 25u) r0 = 14u; else r0 = 139u;
  s += r0;
  }
  if (a == 9u) r2 = 156u; else r2 = 70u;
  s += r2;
  r2 = 1u; if (b < 18u) r2 = 2u; if (b < 18u) r2 = 9u;
  s += r2;
  if (a == 18u && b == 0u) r3 = 153u; else r3 = 34u;
  s += r3;
  return s;
}

unsigned f46(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  if (a == 21u && b == 4u) r2 = 173u; else r2 = 97u;
  s += r2;
  r2 = 76u;
  s += r2;
  if (b < 14u) {
  if (((b & a) <= a)) r2 = 164u; else r2 = 28u;
  s += r2;
  }
  if (a < 19u) r0 = 91u; else r0 = 149u;
  s += r0;
  if (((b & a) <= a)) r3 = 188u; else r3 = 52u;
  s += r3;
  if (a < 6u) {
  if (!(((a | b) >= a))) r1 = 78u; else r1 = 186u;
  s += r1;
  }
  if (b < 25u) {
  if (b < 17u) r0 = 12u; else r0 = 127u;
  s += r0;
  }
  r3 = 1u; if (a < 13u) r3 = 2u; if (a < 13u) r3 = 9u;
  s += r3;
  return s;
}

unsigned f47(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  if (((b | a) >= b)) r2 = 134u; else r2 = 49u;
  s += r2;
  if (a < 17u) {
  r3 = 1u; if (a < 17u) r3 = 2u; if (a < 17u) r3 = 9u;
  s += r3;
  }
  if (b < 10u) {
  i = 0u; do { i = i + 1u; s = s + i; } while (i < 5u);
  }
  if (a < 6u) {
  if (((b & a) <= a)) r1 = 146u; else r1 = 52u;
  s += r1;
  }
  if (a < 4u) {
  r1 = 87u;
  s += r1;
  }
  if (b < 8u) {
  if (a < 16u) r2 = 6u; else r2 = 125u;
  s += r2;
  }
  if (((a * a) & 3u) != 2u) r0 = 107u; else r0 = 86u;
  s += r0;
  return s;
}

unsigned f48(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  if (a < 20u) {
  r1 = 1u; if (b < 19u) r1 = 2u; if (b < 19u) r1 = 9u;
  s += r1;
  }
  if (a < 8u) {
  if (a == 9u) r3 = 177u; else r3 = 57u;
  s += r3;
  }
  r0 = 1u; if (a < 20u) r0 = 2u; if (a < 20u) r0 = 9u;
  s += r0;
  i = 0u; do { i = i + 1u; s = s + i; } while (i < 5u);
  i = 0u; do { i = i + 1u; s = s + i; } while (i < 5u);
  r1 = 1u; if (a < 16u) r1 = 2u; if (a < 16u) r1 = 9u;
  s += r1;
  return s;
}

unsigned f49(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  if (a < 12u) {
  r2 = 1u; if (b < 22u) r2 = 2u; if (b < 22u) r2 = 9u;
  s += r2;
  }
  if (a == 25u) r0 = 114u; else r0 = 98u;
  s += r0;
  if (a < 21u) r1 = 68u; else r1 = 167u;
  s += r1;
  if (a < 26u) {
  if (!(((a * (a + 1u)) & 1u) == 0u)) r1 = 83u; else r1 = 118u;
  s += r1;
  }
  r2 = 30u;
  s += r2;
  if (a == 7u) r3 = 110u; else r3 = 35u;
  s += r3;
  return s;
}

unsigned f50(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  if (!(((b | a) >= b))) r3 = 46u; else r3 = 136u;
  s += r3;
  if (a < 24u) {
  if (b < 24u) r2 = 88u; else r2 = 127u;
  s += r2;
  }
  if (b < 10u) r0 = 31u; else r0 = 170u;
  s += r0;
  if (a < 17u) {
  r0 = 1u; if (a < 10u) r0 = 2u; if (a < 10u) r0 = 9u;
  s += r0;
  }
  if (b < 12u) {
  r2 = 63u;
  s += r2;
  }
  if (b < 22u) r2 = 92u; else r2 = 170u;
  s += r2;
  i = 0u; do { i = i + 1u; s = s + i; } while (i < 3u);
  return s;
}

unsigned f51(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  r3 = 1u; if (a < 15u) r3 = 2u; if (a < 15u) r3 = 9u;
  s += r3;
  if (a < 5u) {
  if (a == 20u && b == 10u) r2 = 157u; else r2 = 34u;
  s += r2;
  }
  if (((a | b) >= a)) r1 = 131u; else r1 = 67u;
  s += r1;
  r0 = 1u; if (a < 11u) r0 = 2u; if (a < 11u) r0 = 9u;
  s += r0;
  if (b < 5u) {
  if (a < 11u) r0 = 98u; else r0 = 193u;
  s += r0;
  }
  return s;
}

unsigned f52(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  r0 = 1u; if (b < 22u) r0 = 2u; if (b < 22u) r0 = 9u;
  s += r0;
  if (a == 3u && b == 13u) r1 = 190u; else r1 = 33u;
  s += r1;
  if (a == 14u) r2 = 180u; else r2 = 49u;
  s += r2;
  if (b < 7u) r2 = 43u; else r2 = 107u;
  s += r2;
  return s;
}

unsigned f53(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  if (((a & b) <= b)) r3 = 170u; else r3 = 8u;
  s += r3;
  if (a == 26u) r0 = 122u; else r0 = 63u;
  s += r0;
  r1 = 70u;
  s += r1;
  if (b < 15u) {
  r2 = 37u;
  s += r2;
  }
  if (((b | a) >= b)) r1 = 133u; else r1 = 44u;
  s += r1;
  if (((b | a) >= b)) r2 = 169u; else r2 = 44u;
  s += r2;
  return s;
}

unsigned f54(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  if (b < 27u) {
  if (((a & b) <= b)) r1 = 119u; else r1 = 33u;
  s += r1;
  }
  if (a < 14u) {
  i = 0u; do { i = i + 1u; s = s + i; } while (i < 5u);
  }
  if (!(((b * (b + 1u)) & 1u) == 0u)) r0 = 79u; else r0 = 139u;
  s += r0;
  if (a < 27u) {
  if (!(((b * b) & 3u) != 2u)) r2 = 3u; else r2 = 171u;
  s += r2;
  }
  if (a < 26u) {
  if (!(((a * a) & 3u) != 2u)) r1 = 15u; else r1 = 164u;
  s += r1;
  }
  if (a < 5u) {
  if (!(((b & a) <= a))) r1 = 47u; else r1 = 101u;
  s += r1;
  }
  if (a < 23u) {
  if (a < 17u) r3 = 4u; else r3 = 172u;
  s += r3;
  }
  return s;
}

unsigned f55(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  if (a < 25u) r2 = 4u; else r2 = 116u;
  s += r2;
  if (!(((b | a) >= b))) r3 = 45u; else r3 = 145u;
  s += r3;
  if (a < 24u) {
  if (a < 12u) r3 = 44u; else r3 = 116u;
  s += r3;
  }
  if (((b * b) & 3u) != 2u) r1 = 116u; else r1 = 17u;
  s += r1;
  r3 = 84u;
  s += r3;
  return s;
}

unsigned f56(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  r1 = 1u; if (b < 22u) r1 = 2u; if (b < 22u) r1 = 9u;
  s += r1;
  if (b < 7u) {
  if (a == 0u && b == 26u) r0 = 173u; else r0 = 90u;
  s += r0;
  }
  if (!(((b * b) & 3u) != 2u)) r3 = 50u; else r3 = 174u;
  s += r3;
  if (!(((a * (a + 1u)) & 1u) == 0u)) r3 = 54u; else r3 = 174u;
  s += r3;
  if (!(((b | a) >= b))) r1 = 8u; else r1 = 121u;
  s += r1;
  return s;
}

unsigned f57(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  i = 0u; do { i = i + 1u; s = s + i; } while (i < 5u);
  if (a == 11u && b == 23u) r1 = 153u; else r1 = 31u;
  s += r1;
  if (a < 27u) {
  if (!(((b | a) >= b))) r0 = 73u; else r0 = 119u;
  s += r0;
  }
  r1 = 1u; if (b < 15u) r1 = 2u; if (b < 15u) r1 = 9u;
  s += r1;
  return s;
}

unsigned f58(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  if (a < 5u) {
  if (!(((b & a) <= a))) r3 = 26u; else r3 = 143u;
  s += r3;
  }
  if (((a * (a + 1u)) & 1u) == 0u) r1 = 116u; else r1 = 38u;
  s += r1;
  r0 = 1u; if (a < 8u) r0 = 2u; if (a < 8u) r0 = 9u;
  s += r0;
  if (a < 23u) r3 = 58u; else r3 = 151u;
  s += r3;
  if (a < 18u) {
  r1 = 1u; if (b < 23u) r1 = 2u; if (b < 23u) r1 = 9u;
  s += r1;
  }
  r0 = 94u;
  s += r0;
  if (b < 24u) {
  if (((b * b) & 3u) != 2u) r0 = 175u; else r0 = 93u;
  s += r0;
  }
  if (a < 21u) r2 = 50u; else r2 = 165u;
  s += r2;
  return s;
}

unsigned f59(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  r2 = 73u;
  s += r2;
  if (a == 20u && b == 10u) r3 = 104u; else r3 = 13u;
  s += r3;
  if (b < 23u) {
  if (b < 12u) r1 = 99u; else r1 = 198u;
  s += r1;
  }
  if (!(((b | a) >= b))) r0 = 58u; else r0 = 122u;
  s += r0;
  if (a < 22u) {
  if (((b & a) <= a)) r3 = 158u; else r3 = 19u;
  s += r3;
  }
  return s;
}

unsigned f60(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  if (a < 6u) {
  if (!(((a * (a + 1u)) & 1u) == 0u)) r0 = 37u; else r0 = 170u;
  s += r0;
  }
  if (a < 5u) {
  if (((a | b) >= a)) r0 = 187u; else r0 = 68u;
  s += r0;
  }
  if (!(((a & b) <= b))) r2 = 43u; else r2 = 167u;
  s += r2;
  if (b < 27u) {
  r2 = 1u; if (b < 22u) r2 = 2u; if (b < 22u) r2 = 9u;
  s += r2;
  }
  r0 = 11u;
  s += r0;
  if (((a & b) <= b)) r3 = 150u; else r3 = 56u;
  s += r3;
  if (b < 7u) {
  r3 = 1u; if (a < 18u) r3 = 2u; if (a < 18u) r3 = 9u;
  s += r3;
  }
  return s;
}

unsigned f61(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  if (a < 16u) {
  r3 = 1u; if (a < 23u) r3 = 2u; if (a < 23u) r3 = 9u;
  s += r3;
  }
  if (b < 11u) {
  r0 = 1u; if (b < 17u) r0 = 2u; if (b < 17u) r0 = 9u;
  s += r0;
  }
  if (a < 24u) {
  if (b < 19u) r3 = 98u; else r3 = 191u;
  s += r3;
  }
  if (!(((a | b) >= a))) r2 = 20u; else r2 = 119u;
  s += r2;
  r0 = 1u; if (b < 18u) r0 = 2u; if (b < 18u) r0 = 9u;
  s += r0;
  r0 = 1u; if (b < 9u) r0 = 2u; if (b < 9u) r0 = 9u;
  s += r0;
  if (a < 26u) {
  if (((a * (a + 1u)) & 1u) == 0u) r3 = 155u; else r3 = 61u;
  s += r3;
  }
  if (b < 7u) {
  r2 = 70u;
  s += r2;
  }
  return s;
}

unsigned f62(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  if (a == 5u) r3 = 137u; else r3 = 99u;
  s += r3;
  if (((b * (b + 1u)) & 1u) == 0u) r2 = 152u; else r2 = 41u;
  s += r2;
  if (b < 10u) r2 = 15u; else r2 = 102u;
  s += r2;
  if (((a | b) >= a)) r0 = 117u; else r0 = 15u;
  s += r0;
  i = 0u; do { i = i + 1u; s = s + i; } while (i < 6u);
  if (b < 25u) {
  r3 = 76u;
  s += r3;
  }
  r0 = 1u; if (a < 12u) r0 = 2u; if (a < 12u) r0 = 9u;
  s += r0;
  if (a < 20u) r2 = 23u; else r2 = 167u;
  s += r2;
  return s;
}

unsigned f63(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  r2 = 41u;
  s += r2;
  if (b < 21u) {
  if (((b & a) <= a)) r1 = 118u; else r1 = 26u;
  s += r1;
  }
  r0 = 62u;
  s += r0;
  if (a < 7u) {
  if (((a * a) & 3u) != 2u) r2 = 172u; else r2 = 81u;
  s += r2;
  }
  if (b < 14u) {
  r0 = 1u; if (b < 16u) r0 = 2u; if (b < 16u) r0 = 9u;
  s += r0;
  }
  if (a < 20u) r2 = 32u; else r2 = 172u;
  s += r2;
  return s;
}

unsigned f64(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  if (a < 17u) {
  if (b < 19u) r0 = 43u; else r0 = 111u;
  s += r0;
  }
  if (b < 11u) {
  r0 = 1u; if (b < 9u) r0 = 2u; if (b < 9u) r0 = 9u;
  s += r0;
  }
  if (!(((a * a) & 3u) != 2u)) r0 = 98u; else r0 = 112u;
  s += r0;
  if (a < 8u) {
  if (a < 18u) r2 = 62u; else r2 = 199u;
  s += r2;
  }
  if (a == 10u && b == 21u) r0 = 173u; else r0 = 63u;
  s += r0;
  r2 = 17u;
  s += r2;
  i = 0u; do { i = i + 1u; s = s + i; } while (i < 5u);
  return s;
}

unsigned f65(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  if (a < 16u) {
  r2 = 1u; if (b < 18u) r2 = 2u; if (b < 18u) r2 = 9u;
  s += r2;
  }
  if (((b * b) & 3u) != 2u) r2 = 131u; else r2 = 41u;
  s += r2;
  if (b < 27u) {
  r1 = 1u; if (b < 18u) r1 = 2u; if (b < 18u) r1 = 9u;
  s += r1;
  }
  if (a < 15u) r1 = 46u; else r1 = 168u;
  s += r1;
  r2 = 92u;
  s += r2;
  if (a == 24u) r2 = 157u; else r2 = 60u;
  s += r2;
  if (b < 23u) {
  r1 = 1u; if (b < 21u) r1 = 2u; if (b < 21u) r1 = 9u;
  s += r1;
  }
  if (a == 0u) r1 = 114u; else r1 = 47u;
  s += r1;
  return s;
}

unsigned f66(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  if (a == 12u) r0 = 183u; else r0 = 77u;
  s += r0;
  if (a < 6u) {
  r1 = 1u; if (a < 18u) r1 = 2u; if (a < 18u) r1 = 9u;
  s += r1;
  }
  if (b < 5u) {
  if (a == 25u && b == 0u) r0 = 186u; else r0 = 79u;
  s += r0;
  }
  r3 = 95u;
  s += r3;
  if (b < 19u) {
  if (b < 8u) r3 = 59u; else r3 = 192u;
  s += r3;
  }
  if (a == 27u && b == 4u) r2 = 137u; else r2 = 19u;
  s += r2;
  if (b < 8u) r0 = 17u; else r0 = 163u;
  s += r0;
  return s;
}

unsigned f67(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  if (a < 23u) {
  i = 0u; do { i = i + 1u; s = s + i; } while (i < 6u);
  }
  if (a < 20u) r1 = 63u; else r1 = 139u;
  s += r1;
  if (((b * (b + 1u)) & 1u) == 0u) r2 = 166u; else r2 = 2u;
  s += r2;
  if (!(((a * a) & 3u) != 2u)) r2 = 69u; else r2 = 164u;
  s += r2;
  r3 = 1u; if (b < 22u) r3 = 2u; if (b < 22u) r3 = 9u;
  s += r3;
  return s;
}

unsigned f68(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  if (b < 11u) {
  r1 = 1u; if (b < 11u) r1 = 2u; if (b < 11u) r1 = 9u;
  s += r1;
  }
  if (a < 11u) {
  if (!(((b & a) <= a))) r0 = 2u; else r0 = 164u;
  s += r0;
  }
  if (a < 8u) {
  r2 = 1u; if (a < 20u) r2 = 2u; if (a < 20u) r2 = 9u;
  s += r2;
  }
  r0 = 20u;
  s += r0;
  return s;
}

unsigned f69(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  if (a < 27u) {
  if (a < 17u) r0 = 70u; else r0 = 180u;
  s += r0;
  }
  if (a == 27u && b == 5u) r1 = 102u; else r1 = 54u;
  s += r1;
  r1 = 1u; if (b < 9u) r1 = 2u; if (b < 9u) r1 = 9u;
  s += r1;
  r0 = 1u; if (a < 8u) r0 = 2u; if (a < 8u) r0 = 9u;
  s += r0;
  return s;
}

unsigned f70(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  if (a < 12u) {
  i = 0u; do { i = i + 1u; s = s + i; } while (i < 4u);
  }
  if (a == 13u) r0 = 169u; else r0 = 17u;
  s += r0;
  if (a == 5u) r0 = 170u; else r0 = 37u;
  s += r0;
  if (a < 20u) {
  r2 = 1u; if (b < 19u) r2 = 2u; if (b < 19u) r2 = 9u;
  s += r2;
  }
  if (a < 16u) {
  r1 = 25u;
  s += r1;
  }
  if (b < 14u) r3 = 1u; else r3 = 158u;
  s += r3;
  if (((b * b) & 3u) != 2u) r0 = 116u; else r0 = 95u;
  s += r0;
  return s;
}

unsigned f71(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  if (a < 24u) {
  r2 = 1u; if (b < 9u) r2 = 2u; if (b < 9u) r2 = 9u;
  s += r2;
  }
  r3 = 1u; if (a < 22u) r3 = 2u; if (a < 22u) r3 = 9u;
  s += r3;
  i = 0u; do { i = i + 1u; s = s + i; } while (i < 3u);
  i = 0u; do { i = i + 1u; s = s + i; } while (i < 6u);
  r3 = 1u; if (a < 11u) r3 = 2u; if (a < 11u) r3 = 9u;
  s += r3;
  return s;
}

unsigned f72(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  r0 = 53u;
  s += r0;
  if (a < 14u) {
  if (!(((b * b) & 3u) != 2u)) r1 = 52u; else r1 = 144u;
  s += r1;
  }
  r3 = 63u;
  s += r3;
  if (a < 10u) {
  r3 = 1u; if (b < 17u) r3 = 2u; if (b < 17u) r3 = 9u;
  s += r3;
  }
  if (b < 6u) {
  r3 = 1u; if (a < 23u) r3 = 2u; if (a < 23u) r3 = 9u;
  s += r3;
  }
  return s;
}

unsigned f73(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  if (a < 17u) r2 = 11u; else r2 = 142u;
  s += r2;
  if (((b * b) & 3u) != 2u) r2 = 183u; else r2 = 50u;
  s += r2;
  if (!(((a | b) >= a))) r1 = 16u; else r1 = 139u;
  s += r1;
  if (b < 6u) {
  if (((a * (a + 1u)) & 1u) == 0u) r0 = 164u; else r0 = 87u;
  s += r0;
  }
  if (a < 13u) r1 = 10u; else r1 = 138u;
  s += r1;
  r2 = 1u; if (a < 20u) r2 = 2u; if (a < 20u) r2 = 9u;
  s += r2;
  return s;
}

unsigned f74(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  r0 = 81u;
  s += r0;
  if (b < 18u) {
  if (a == 9u && b == 10u) r3 = 144u; else r3 = 24u;
  s += r3;
  }
  if (b < 24u) {
  i = 0u; do { i = i + 1u; s = s + i; } while (i < 5u);
  }
  if (((b & a) <= a)) r0 = 114u; else r0 = 98u;
  s += r0;
  r1 = 9u;
  s += r1;
  return s;
}

unsigned f75(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  r2 = 1u; if (a < 21u) r2 = 2u; if (a < 21u) r2 = 9u;
  s += r2;
  if (((a & b) <= b)) r0 = 181u; else r0 = 66u;
  s += r0;
  if (b < 19u) {
  if (a == 18u && b == 10u) r3 = 108u; else r3 = 96u;
  s += r3;
  }
  if (a == 31u && b == 7u) r2 = 153u; else r2 = 24u;
  s += r2;
  if (a < 25u) r3 = 99u; else r3 = 105u;
  s += r3;
  r1 = 86u;
  s += r1;
  r3 = 1u; if (b < 8u) r3 = 2u; if (b < 8u) r3 = 9u;
  s += r3;
  if (b < 6u) r2 = 86u; else r2 = 144u;
  s += r2;
  return s;
}

unsigned f76(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  if (b < 6u) {
  r2 = 1u; if (a < 9u) r2 = 2u; if (a < 9u) r2 = 9u;
  s += r2;
  }
  if (a < 14u) {
  if (((a * (a + 1u)) & 1u) == 0u) r2 = 159u; else r2 = 53u;
  s += r2;
  }
  r0 = 1u; if (b < 22u) r0 = 2u; if (b < 22u) r0 = 9u;
  s += r0;
  if (((a * a) & 3u) != 2u) r3 = 119u; else r3 = 91u;
  s += r3;
  r0 = 1u; if (a < 21u) r0 = 2u; if (a < 21u) r0 = 9u;
  s += r0;
  if (a < 22u) r1 = 89u; else r1 = 139u;
  s += r1;
  return s;
}

unsigned f77(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  r0 = 1u; if (a < 9u) r0 = 2u; if (a < 9u) r0 = 9u;
  s += r0;
  if (a < 14u) {
  i = 0u; do { i = i + 1u; s = s + i; } while (i < 5u);
  }
  if (b < 17u) {
  if (a < 15u) r0 = 6u; else r0 = 101u;
  s += r0;
  }
  if (!(((b * (b + 1u)) & 1u) == 0u)) r0 = 82u; else r0 = 143u;
  s += r0;
  return s;
}

unsigned f78(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  if (a < 7u) r1 = 58u; else r1 = 132u;
  s += r1;
  r0 = 1u; if (a < 14u) r0 = 2u; if (a < 14u) r0 = 9u;
  s += r0;
  if (a < 20u) {
  if (!(((a * (a + 1u)) & 1u) == 0u)) r0 = 21u; else r0 = 180u;
  s += r0;
  }
  if (a == 1u) r3 = 111u; else r3 = 46u;
  s += r3;
  if (a == 27u && b == 28u) r0 = 188u; else r0 = 48u;
  s += r0;
  i = 0u; do { i = i + 1u; s = s + i; } while (i < 6u);
  return s;
}

unsigned f79(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  if (((b | a) >= b)) r3 = 172u; else r3 = 62u;
  s += r3;
  if (a < 19u) {
  r0 = 1u; if (b < 16u) r0 = 2u; if (b < 16u) r0 = 9u;
  s += r0;
  }
  r2 = 1u; if (a < 17u) r2 = 2u; if (a < 17u) r2 = 9u;
  s += r2;
  r3 = 1u; if (a < 18u) r3 = 2u; if (a < 18u) r3 = 9u;
  s += r3;
  if (!(((a * (a + 1u)) & 1u) == 0u)) r2 = 21u; else r2 = 144u;
  s += r2;
  return s;
}

unsigned f80(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  if (b < 9u) {
  if (a == 16u && b == 13u) r0 = 149u; else r0 = 17u;
  s += r0;
  }
  if (b < 16u) {
  r2 = 1u; if (b < 23u) r2 = 2u; if (b < 23u) r2 = 9u;
  s += r2;
  }
  if (a < 10u) {
  r0 = 72u;
  s += r0;
  }
  if (b < 23u) r1 = 30u; else r1 = 139u;
  s += r1;
  if (a == 27u && b == 12u) r2 = 194u; else r2 = 74u;
  s += r2;
  if (a < 17u) r3 = 49u; else r3 = 127u;
  s += r3;
  r1 = 1u; if (b < 9u) r1 = 2u; if (b < 9u) r1 = 9u;
  s += r1;
  return s;
}

unsigned f81(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  if (b < 20u) {
  if (a == 5u && b == 24u) r0 = 112u; else r0 = 47u;
  s += r0;
  }
  if (b < 14u) {
  if (((b * b) & 3u) != 2u) r0 = 160u; else r0 = 3u;
  s += r0;
  }
  if (a < 13u) {
  r2 = 1u; if (a < 20u) r2 = 2u; if (a < 20u) r2 = 9u;
  s += r2;
  }
  if (a < 27u) {
  if (a == 19u && b == 18u) r0 = 135u; else r0 = 69u;
  s += r0;
  }
  if (a < 12u) {
  if (((b & a) <= a)) r3 = 154u; else r3 = 65u;
  s += r3;
  }
  r1 = 1u; if (b < 16u) r1 = 2u; if (b < 16u) r1 = 9u;
  s += r1;
  if (((a & b) <= b)) r2 = 101u; else r2 = 66u;
  s += r2;
  return s;
}

unsigned f82(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  if (a < 23u) r2 = 55u; else r2 = 124u;
  s += r2;
  r3 = 1u; if (b < 14u) r3 = 2u; if (b < 14u) r3 = 9u;
  s += r3;
  if (b < 20u) {
  r3 = 1u; if (a < 15u) r3 = 2u; if (a < 15u) r3 = 9u;
  s += r3;
  }
  r2 = 1u; if (a < 20u) r2 = 2u; if (a < 20u) r2 = 9u;
  s += r2;
  if (a < 24u) {
  if (a == 29u) r3 = 147u; else r3 = 90u;
  s += r3;
  }
  if (b < 24u) {
  if (a < 6u) r0 = 24u; else r0 = 173u;
  s += r0;
  }
  if (a < 27u) {
  i = 0u; do { i = i + 1u; s = s + i; } while (i < 3u);
  }
  r1 = 1u; if (a < 9u) r1 = 2u; if (a < 9u) r1 = 9u;
  s += r1;
  return s;
}

unsigned f83(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  if (!(((a | b) >= a))) r3 = 81u; else r3 = 171u;
  s += r3;
  if (b < 21u) {
  r3 = 1u; if (a < 18u) r3 = 2u; if (a < 18u) r3 = 9u;
  s += r3;
  }
  r0 = 1u; if (b < 19u) r0 = 2u; if (b < 19u) r0 = 9u;
  s += r0;
  if (a < 12u) r2 = 33u; else r2 = 119u;
  s += r2;
  r1 = 88u;
  s += r1;
  i = 0u; do { i = i + 1u; s = s + i; } while (i < 5u);
  return s;
}

unsigned f84(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  r3 = 72u;
  s += r3;
  r3 = 83u;
  s += r3;
  if (a < 14u) r2 = 31u; else r2 = 104u;
  s += r2;
  if (a == 23u) r1 = 146u; else r1 = 28u;
  s += r1;
  if (b < 20u) {
  if (((b * b) & 3u) != 2u) r0 = 180u; else r0 = 96u;
  s += r0;
  }
  return s;
}

unsigned f85(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  if (b < 14u) {
  if (((b * (b + 1u)) & 1u) == 0u) r2 = 135u; else r2 = 80u;
  s += r2;
  }
  i = 0u; do { i = i + 1u; s = s + i; } while (i < 2u);
  if (a < 23u) {
  if (a == 25u) r3 = 192u; else r3 = 25u;
  s += r3;
  }
  r0 = 1u; if (b < 17u) r0 = 2u; if (b < 17u) r0 = 9u;
  s += r0;
  if (a < 18u) {
  r0 = 25u;
  s += r0;
  }
  if (b < 24u) {
  if (!(((b & a) <= a))) r0 = 36u; else r0 = 114u;
  s += r0;
  }
  if (a < 24u) r1 = 27u; else r1 = 107u;
  s += r1;
  return s;
}

unsigned f86(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  i = 0u; do { i = i + 1u; s = s + i; } while (i < 4u);
  r0 = 1u; if (a < 16u) r0 = 2u; if (a < 16u) r0 = 9u;
  s += r0;
  if (!(((b * (b + 1u)) & 1u) == 0u)) r3 = 17u; else r3 = 130u;
  s += r3;
  if (!(((b * b) & 3u) != 2u)) r1 = 65u; else r1 = 121u;
  s += r1;
  if (((b & a) <= a)) r2 = 170u; else r2 = 35u;
  s += r2;
  return s;
}

unsigned f87(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  if (b < 10u) {
  if (((a & b) <= b)) r2 = 173u; else r2 = 2u;
  s += r2;
  }
  if (a == 16u) r3 = 111u; else r3 = 36u;
  s += r3;
  if (!(((a * a) & 3u) != 2u)) r1 = 89u; else r1 = 159u;
  s += r1;
  if (b < 22u) {
  r1 = 1u; if (b < 8u) r1 = 2u; if (b < 8u) r1 = 9u;
  s += r1;
  }
  if (((a * (a + 1u)) & 1u) == 0u) r0 = 136u; else r0 = 96u;
  s += r0;
  if (a < 16u) {
  r3 = 18u;
  s += r3;
  }
  if (((a * a) & 3u) != 2u) r0 = 113u; else r0 = 12u;
  s += r0;
  if (((b | a) >= b)) r2 = 185u; else r2 = 38u;
  s += r2;
  return s;
}

unsigned f88(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  r1 = 66u;
  s += r1;
  if (a < 22u) r1 = 89u; else r1 = 109u;
  s += r1;
  if (((a * a) & 3u) != 2u) r2 = 163u; else r2 = 61u;
  s += r2;
  r1 = 9u;
  s += r1;
  r0 = 1u; if (b < 16u) r0 = 2u; if (b < 16u) r0 = 9u;
  s += r0;
  if (a < 27u) {
  if (((b * b) & 3u) != 2u) r0 = 126u; else r0 = 87u;
  s += r0;
  }
  if (a == 7u) r2 = 191u; else r2 = 66u;
  s += r2;
  if (a < 24u) {
  if (a < 20u) r0 = 52u; else r0 = 163u;
  s += r0;
  }
  return s;
}

unsigned f89(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  if (b < 23u) {
  r2 = 20u;
  s += r2;
  }
  if (b < 11u) r0 = 38u; else r0 = 132u;
  s += r0;
  if (a < 8u) {
  if (!(((a * a) & 3u) != 2u)) r2 = 90u; else r2 = 151u;
  s += r2;
  }
  if (!(((a * a) & 3u) != 2u)) r2 = 56u; else r2 = 171u;
  s += r2;
  r0 = 11u;
  s += r0;
  r3 = 1u; if (a < 12u) r3 = 2u; if (a < 12u) r3 = 9u;
  s += r3;
  if (b < 18u) {
  if (a == 19u) r1 = 191u; else r1 = 89u;
  s += r1;
  }
  return s;
}

unsigned f90(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  if (a < 23u) {
  r1 = 15u;
  s += r1;
  }
  if (a == 9u) r3 = 107u; else r3 = 14u;
  s += r3;
  if (b < 4u) {
  if (b < 14u) r2 = 37u; else r2 = 133u;
  s += r2;
  }
  if (a < 16u) {
  if (a == 30u) r0 = 139u; else r0 = 18u;
  s += r0;
  }
  if (((a * a) & 3u) != 2u) r1 = 150u; else r1 = 89u;
  s += r1;
  if (a < 24u) {
  if (a == 20u && b == 4u) r1 = 124u; else r1 = 38u;
  s += r1;
  }
  return s;
}

unsigned f91(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  if (a < 7u) {
  r3 = 1u; if (b < 11u) r3 = 2u; if (b < 11u) r3 = 9u;
  s += r3;
  }
  r0 = 1u; if (b < 14u) r0 = 2u; if (b < 14u) r0 = 9u;
  s += r0;
  if (((a | b) >= a)) r2 = 144u; else r2 = 48u;
  s += r2;
  r2 = 1u; if (a < 12u) r2 = 2u; if (a < 12u) r2 = 9u;
  s += r2;
  if (b < 4u) {
  if (!(((a * (a + 1u)) & 1u) == 0u)) r3 = 20u; else r3 = 187u;
  s += r3;
  }
  if (a < 16u) {
  r1 = 1u; if (a < 18u) r1 = 2u; if (a < 18u) r1 = 9u;
  s += r1;
  }
  return s;
}

unsigned f92(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  if (a < 24u) {
  if (!(((a | b) >= a))) r1 = 97u; else r1 = 151u;
  s += r1;
  }
  if (a == 16u && b == 21u) r3 = 137u; else r3 = 90u;
  s += r3;
  r3 = 4u;
  s += r3;
  r3 = 1u; if (a < 15u) r3 = 2u; if (a < 15u) r3 = 9u;
  s += r3;
  return s;
}

unsigned f93(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  r2 = 1u; if (a < 12u) r2 = 2u; if (a < 12u) r2 = 9u;
  s += r2;
  if (!(((a * a) & 3u) != 2u)) r3 = 11u; else r3 = 145u;
  s += r3;
  if (b < 21u) {
  if (a < 10u) r0 = 79u; else r0 = 136u;
  s += r0;
  }
  i = 0u; do { i = i + 1u; s = s + i; } while (i < 4u);
  if (!(((a * a) & 3u) != 2u)) r0 = 14u; else r0 = 165u;
  s += r0;
  if (a == 8u) r3 = 172u; else r3 = 2u;
  s += r3;
  if (b < 10u) r0 = 23u; else r0 = 182u;
  s += r0;
  i = 0u; do { i = i + 1u; s = s + i; } while (i < 4u);
  return s;
}

unsigned f94(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  if (!(((a * (a + 1u)) & 1u) == 0u)) r1 = 37u; else r1 = 166u;
  s += r1;
  if (b < 8u) {
  if (((a | b) >= a)) r3 = 144u; else r3 = 55u;
  s += r3;
  }
  if (b < 9u) r0 = 86u; else r0 = 179u;
  s += r0;
  if (!(((b * (b + 1u)) & 1u) == 0u)) r0 = 59u; else r0 = 154u;
  s += r0;
  if (a < 20u) r3 = 46u; else r3 = 182u;
  s += r3;
  if (b < 7u) r0 = 2u; else r0 = 188u;
  s += r0;
  if (((a * a) & 3u) != 2u) r1 = 149u; else r1 = 46u;
  s += r1;
  r2 = 1u; if (b < 20u) r2 = 2u; if (b < 20u) r2 = 9u;
  s += r2;
  return s;
}

unsigned f95(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  if (b < 25u) {
  if (((a & b) <= b)) r1 = 107u; else r1 = 43u;
  s += r1;
  }
  if (!(((a & b) <= b))) r1 = 40u; else r1 = 120u;
  s += r1;
  r1 = 1u; if (b < 13u) r1 = 2u; if (b < 13u) r1 = 9u;
  s += r1;
  if (a < 11u) {
  if (!(((b & a) <= a))) r2 = 32u; else r2 = 135u;
  s += r2;
  }
  if (a < 13u) {
  r3 = 11u;
  s += r3;
  }
  i = 0u; do { i = i + 1u; s = s + i; } while (i < 6u);
  if (((b | a) >= b)) r3 = 130u; else r3 = 84u;
  s += r3;
  return s;
}

unsigned f96(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  r0 = 1u; if (b < 23u) r0 = 2u; if (b < 23u) r0 = 9u;
  s += r0;
  if (a == 17u && b == 11u) r0 = 174u; else r0 = 95u;
  s += r0;
  if (b < 7u) {
  r0 = 1u; if (a < 12u) r0 = 2u; if (a < 12u) r0 = 9u;
  s += r0;
  }
  if (b < 23u) {
  i = 0u; do { i = i + 1u; s = s + i; } while (i < 4u);
  }
  return s;
}

unsigned f97(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  if (a == 4u) r2 = 145u; else r2 = 12u;
  s += r2;
  r0 = 1u; if (a < 13u) r0 = 2u; if (a < 13u) r0 = 9u;
  s += r0;
  if (b < 11u) {
  if (a == 24u && b == 11u) r0 = 111u; else r0 = 80u;
  s += r0;
  }
  if (a < 26u) {
  if (a < 22u) r3 = 89u; else r3 = 140u;
  s += r3;
  }
  if (b < 21u) {
  if (a == 0u) r1 = 190u; else r1 = 81u;
  s += r1;
  }
  if (b < 18u) {
  i = 0u; do { i = i + 1u; s = s + i; } while (i < 2u);
  }
  return s;
}

unsigned f98(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  if (!(((a | b) >= a))) r1 = 32u; else r1 = 129u;
  s += r1;
  if (b < 13u) {
  if (((a | b) >= a)) r2 = 148u; else r2 = 14u;
  s += r2;
  }
  if (a == 22u && b == 3u) r2 = 118u; else r2 = 9u;
  s += r2;
  if (!(((a * a) & 3u) != 2u)) r1 = 71u; else r1 = 171u;
  s += r1;
  if (a == 14u) r2 = 158u; else r2 = 29u;
  s += r2;
  return s;
}

unsigned f99(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  if (a < 9u) {
  if (((a * a) & 3u) != 2u) r1 = 145u; else r1 = 89u;
  s += r1;
  }
  if (a == 9u && b == 12u) r1 = 161u; else r1 = 24u;
  s += r1;
  if (!(((b | a) >= b))) r3 = 91u; else r3 = 105u;
  s += r3;
  if (b < 24u) r2 = 82u; else r2 = 198u;
  s += r2;
  return s;
}

unsigned f100(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  if (b < 21u) {
  if (a == 11u) r2 = 148u; else r2 = 24u;
  s += r2;
  }
  if (a < 17u) {
  r2 = 96u;
  s += r2;
  }
  if (a < 19u) {
  r3 = 1u; if (b < 22u) r3 = 2u; if (b < 22u) r3 = 9u;
  s += r3;
  }
  if (!(((a | b) >= a))) r0 = 95u; else r0 = 156u;
  s += r0;
  return s;
}

unsigned f101(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  r1 = 1u; if (a < 15u) r1 = 2u; if (a < 15u) r1 = 9u;
  s += r1;
  if (a < 22u) {
  if (((b * (b + 1u)) & 1u) == 0u) r2 = 129u; else r2 = 77u;
  s += r2;
  }
  if (b < 25u) {
  r3 = 1u; if (a < 19u) r3 = 2u; if (a < 19u) r3 = 9u;
  s += r3;
  }
  r0 = 1u; if (b < 16u) r0 = 2u; if (b < 16u) r0 = 9u;
  s += r0;
  return s;
}

unsigned f102(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  if (a < 14u) r0 = 14u; else r0 = 125u;
  s += r0;
  if (a < 16u) r0 = 57u; else r0 = 124u;
  s += r0;
  if (a < 12u) {
  if (b < 20u) r1 = 92u; else r1 = 152u;
  s += r1;
  }
  if (!(((a & b) <= b))) r2 = 52u; else r2 = 168u;
  s += r2;
  r0 = 1u; if (a < 17u) r0 = 2u; if (a < 17u) r0 = 9u;
  s += r0;
  if (b < 20u) {
  r1 = 1u; if (a < 18u) r1 = 2u; if (a < 18u) r1 = 9u;
  s += r1;
  }
  return s;
}

unsigned f103(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  if (a < 7u) {
  if (((a | b) >= a)) r2 = 182u; else r2 = 30u;
  s += r2;
  }
  if (b < 6u) {
  if (!(((a * (a + 1u)) & 1u) == 0u)) r1 = 14u; else r1 = 148u;
  s += r1;
  }
  if (a < 10u) {
  if (a == 9u && b == 19u) r3 = 145u; else r3 = 2u;
  s += r3;
  }
  if (a < 27u) {
  if (!(((b * (b + 1u)) & 1u) == 0u)) r2 = 36u; else r2 = 169u;
  s += r2;
  }
  return s;
}

unsigned f104(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  if (a < 24u) r1 = 54u; else r1 = 115u;
  s += r1;
  if (((b & a) <= a)) r0 = 138u; else r0 = 61u;
  s += r0;
  if (!(((b * b) & 3u) != 2u)) r1 = 90u; else r1 = 159u;
  s += r1;
  if (!(((a * (a + 1u)) & 1u) == 0u)) r3 = 22u; else r3 = 160u;
  s += r3;
  r1 = 1u; if (a < 23u) r1 = 2u; if (a < 23u) r1 = 9u;
  s += r1;
  if (b < 7u) {
  if (((a * (a + 1u)) & 1u) == 0u) r2 = 102u; else r2 = 20u;
  s += r2;
  }
  if (((b * b) & 3u) != 2u) r2 = 168u; else r2 = 36u;
  s += r2;
  if (((a * a) & 3u) != 2u) r3 = 114u; else r3 = 29u;
  s += r3;
  return s;
}

unsigned f105(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  if (a < 5u) {
  if (!(((a & b) <= b))) r1 = 36u; else r1 = 174u;
  s += r1;
  }
  if (b < 24u) {
  r3 = 21u;
  s += r3;
  }
  i = 0u; do { i = i + 1u; s = s + i; } while (i < 4u);
  if (b < 15u) r3 = 43u; else r3 = 189u;
  s += r3;
  r2 = 1u; if (a < 17u) r2 = 2u; if (a < 17u) r2 = 9u;
  s += r2;
  return s;
}

unsigned f106(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  if (a < 17u) {
  r3 = 1u; if (a < 15u) r3 = 2u; if (a < 15u) r3 = 9u;
  s += r3;
  }
  if (a < 18u) {
  if (((a | b) >= a)) r1 = 144u; else r1 = 38u;
  s += r1;
  }
  if (a < 6u) {
  if (!(((b * b) & 3u) != 2u)) r0 = 35u; else r0 = 174u;
  s += r0;
  }
  if (a < 15u) {
  if (a < 14u) r0 = 9u; else r0 = 124u;
  s += r0;
  }
  if (a < 8u) {
  if (a < 23u) r3 = 47u; else r3 = 101u;
  s += r3;
  }
  if (((b & a) <= a)) r2 = 156u; else r2 = 3u;
  s += r2;
  if (a == 3u && b == 8u) r0 = 159u; else r0 = 3u;
  s += r0;
  if (a < 4u) {
  if (a == 31u) r1 = 187u; else r1 = 49u;
  s += r1;
  }
  return s;
}

unsigned f107(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  r3 = 18u;
  s += r3;
  r0 = 1u; if (b < 16u) r0 = 2u; if (b < 16u) r0 = 9u;
  s += r0;
  r0 = 24u;
  s += r0;
  r1 = 1u; if (b < 11u) r1 = 2u; if (b < 11u) r1 = 9u;
  s += r1;
  return s;
}

unsigned f108(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  if (b < 6u) r1 = 24u; else r1 = 193u;
  s += r1;
  r1 = 72u;
  s += r1;
  if (a == 20u) r0 = 139u; else r0 = 44u;
  s += r0;
  if (b < 24u) r2 = 50u; else r2 = 131u;
  s += r2;
  if (((b & a) <= a)) r0 = 166u; else r0 = 43u;
  s += r0;
  r0 = 1u; if (a < 13u) r0 = 2u; if (a < 13u) r0 = 9u;
  s += r0;
  if (a < 11u) {
  if (((a | b) >= a)) r1 = 169u; else r1 = 76u;
  s += r1;
  }
  return s;
}

unsigned f109(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  if (b < 18u) {
  if (!(((a * (a + 1u)) & 1u) == 0u)) r3 = 10u; else r3 = 104u;
  s += r3;
  }
  r2 = 1u; if (a < 18u) r2 = 2u; if (a < 18u) r2 = 9u;
  s += r2;
  if (b < 6u) {
  r3 = 67u;
  s += r3;
  }
  r3 = 1u; if (b < 17u) r3 = 2u; if (b < 17u) r3 = 9u;
  s += r3;
  if (b < 5u) {
  if (((b & a) <= a)) r3 = 139u; else r3 = 15u;
  s += r3;
  }
  return s;
}

unsigned f110(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  if (b < 26u) {
  r0 = 87u;
  s += r0;
  }
  if (((a & b) <= b)) r3 = 103u; else r3 = 33u;
  s += r3;
  r2 = 16u;
  s += r2;
  if (a < 23u) {
  r3 = 93u;
  s += r3;
  }
  if (b < 11u) {
  if (!(((a * a) & 3u) != 2u)) r3 = 71u; else r3 = 133u;
  s += r3;
  }
  r2 = 1u; if (b < 11u) r2 = 2u; if (b < 11u) r2 = 9u;
  s += r2;
  if (a < 7u) {
  if (a < 20u) r1 = 70u; else r1 = 145u;
  s += r1;
  }
  r2 = 1u; if (b < 10u) r2 = 2u; if (b < 10u) r2 = 9u;
  s += r2;
  return s;
}

unsigned f111(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  r1 = 1u; if (b < 19u) r1 = 2u; if (b < 19u) r1 = 9u;
  s += r1;
  if (a < 6u) r0 = 63u; else r0 = 110u;
  s += r0;
  if (a < 4u) {
  if (((a * (a + 1u)) & 1u) == 0u) r0 = 173u; else r0 = 14u;
  s += r0;
  }
  if (a < 17u) {
  i = 0u; do { i = i + 1u; s = s + i; } while (i < 2u);
  }
  i = 0u; do { i = i + 1u; s = s + i; } while (i < 3u);
  if (b < 26u) {
  r1 = 1u; if (b < 12u) r1 = 2u; if (b < 12u) r1 = 9u;
  s += r1;
  }
  if (b < 10u) {
  if (a == 15u) r1 = 159u; else r1 = 37u;
  s += r1;
  }
  if (b < 23u) {
  r2 = 1u; if (b < 17u) r2 = 2u; if (b < 17u) r2 = 9u;
  s += r2;
  }
  return s;
}

unsigned f112(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  if (a < 9u) {
  if (!(((a * (a + 1u)) & 1u) == 0u)) r1 = 39u; else r1 = 124u;
  s += r1;
  }
  if (a == 0u) r1 = 128u; else r1 = 6u;
  s += r1;
  if (((a & b) <= b)) r2 = 110u; else r2 = 48u;
  s += r2;
  if (a < 8u) {
  if (a < 11u) r1 = 21u; else r1 = 174u;
  s += r1;
  }
  i = 0u; do { i = i + 1u; s = s + i; } while (i < 4u);
  return s;
}

unsigned f113(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  if (a == 31u) r0 = 157u; else r0 = 17u;
  s += r0;
  if (a < 24u) {
  r3 = 1u; if (b < 14u) r3 = 2u; if (b < 14u) r3 = 9u;
  s += r3;
  }
  if (a < 26u) {
  i = 0u; do { i = i + 1u; s = s + i; } while (i < 4u);
  }
  if (!(((a | b) >= a))) r2 = 10u; else r2 = 191u;
  s += r2;
  r2 = 99u;
  s += r2;
  r2 = 1u; if (a < 13u) r2 = 2u; if (a < 13u) r2 = 9u;
  s += r2;
  if (a < 13u) {
  if (a < 24u) r0 = 9u; else r0 = 166u;
  s += r0;
  }
  r1 = 1u; if (a < 15u) r1 = 2u; if (a < 15u) r1 = 9u;
  s += r1;
  return s;
}

unsigned f114(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  if (a < 26u) {
  if (((b * (b + 1u)) & 1u) == 0u) r0 = 108u; else r0 = 59u;
  s += r0;
  }
  if (a < 16u) {
  if (a == 11u && b == 28u) r1 = 183u; else r1 = 77u;
  s += r1;
  }
  if (a < 10u) {
  if (((b * b) & 3u) != 2u) r1 = 146u; else r1 = 1u;
  s += r1;
  }
  i = 0u; do { i = i + 1u; s = s + i; } while (i < 6u);
  if (b < 6u) {
  if (b < 17u) r3 = 52u; else r3 = 185u;
  s += r3;
  }
  i = 0u; do { i = i + 1u; s = s + i; } while (i < 4u);
  if (a < 6u) {
  if (((a * (a + 1u)) & 1u) == 0u) r2 = 134u; else r2 = 61u;
  s += r2;
  }
  if (!(((b * (b + 1u)) & 1u) == 0u)) r3 = 19u; else r3 = 153u;
  s += r3;
  return s;
}

unsigned f115(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  if (a < 20u) r3 = 68u; else r3 = 142u;
  s += r3;
  if (a < 11u) {
  if (!(((a & b) <= b))) r2 = 28u; else r2 = 114u;
  s += r2;
  }
  i = 0u; do { i = i + 1u; s = s + i; } while (i < 3u);
  r1 = 1u; if (a < 19u) r1 = 2u; if (a < 19u) r1 = 9u;
  s += r1;
  return s;
}

unsigned f116(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  if (a < 10u) r3 = 46u; else r3 = 131u;
  s += r3;
  if (b < 24u) {
  i = 0u; do { i = i + 1u; s = s + i; } while (i < 5u);
  }
  r2 = 1u; if (a < 19u) r2 = 2u; if (a < 19u) r2 = 9u;
  s += r2;
  if (a < 9u) {
  if (!(((b * (b + 1u)) & 1u) == 0u)) r2 = 4u; else r2 = 115u;
  s += r2;
  }
  if (((a & b) <= b)) r1 = 170u; else r1 = 2u;
  s += r1;
  return s;
}

unsigned f117(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  if (((b * (b + 1u)) & 1u) == 0u) r2 = 155u; else r2 = 68u;
  s += r2;
  if (a < 12u) {
  if (((a & b) <= b)) r3 = 139u; else r3 = 83u;
  s += r3;
  }
  if (!(((a | b) >= a))) r0 = 57u; else r0 = 162u;
  s += r0;
  if (a == 3u) r3 = 122u; else r3 = 1u;
  s += r3;
  r1 = 1u; if (a < 17u) r1 = 2u; if (a < 17u) r1 = 9u;
  s += r1;
  if (b < 22u) {
  if (a == 1u) r1 = 159u; else r1 = 59u;
  s += r1;
  }
  if (b < 15u) {
  r2 = 1u; if (b < 14u) r2 = 2u; if (b < 14u) r2 = 9u;
  s += r2;
  }
  return s;
}

unsigned f118(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  i = 0u; do { i = i + 1u; s = s + i; } while (i < 2u);
  if (b < 26u) {
  r3 = 1u; if (b < 22u) r3 = 2u; if (b < 22u) r3 = 9u;
  s += r3;
  }
  if (!(((b & a) <= a))) r2 = 52u; else r2 = 195u;
  s += r2;
  if (((b * (b + 1u)) & 1u) == 0u) r3 = 111u; else r3 = 4u;
  s += r3;
  if (b < 14u) {
  if (!(((a | b) >= a))) r3 = 4u; else r3 = 125u;
  s += r3;
  }
  if (a < 15u) r2 = 96u; else r2 = 157u;
  s += r2;
  if (a < 4u) {
  i = 0u; do { i = i + 1u; s = s + i; } while (i < 5u);
  }
  return s;
}

unsigned f119(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  if (b < 19u) {
  i = 0u; do { i = i + 1u; s = s + i; } while (i < 3u);
  }
  if (!(((b * (b + 1u)) & 1u) == 0u)) r1 = 27u; else r1 = 172u;
  s += r1;
  if (b < 25u) {
  if (a == 15u) r2 = 162u; else r2 = 7u;
  s += r2;
  }
  if (b < 15u) {
  if (((a | b) >= a)) r0 = 161u; else r0 = 46u;
  s += r0;
  }
  if (b < 22u) r1 = 46u; else r1 = 124u;
  s += r1;
  if (a < 13u) {
  if (!(((b & a) <= a))) r1 = 83u; else r1 = 177u;
  s += r1;
  }
  if (!(((b | a) >= b))) r1 = 9u; else r1 = 186u;
  s += r1;
  return s;
}

unsigned f120(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  if (a == 9u) r3 = 133u; else r3 = 82u;
  s += r3;
  if (a == 11u && b == 11u) r1 = 100u; else r1 = 90u;
  s += r1;
  if (b < 17u) {
  if (b < 17u) r3 = 62u; else r3 = 117u;
  s += r3;
  }
  if (b < 15u) r1 = 4u; else r1 = 168u;
  s += r1;
  r1 = 86u;
  s += r1;
  if (a < 14u) {
  if (a < 10u) r0 = 23u; else r0 = 170u;
  s += r0;
  }
  return s;
}

unsigned f121(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  if (b < 11u) {
  if (a < 19u) r3 = 7u; else r3 = 188u;
  s += r3;
  }
  if (b < 10u) {
  r0 = 1u; if (b < 9u) r0 = 2u; if (b < 9u) r0 = 9u;
  s += r0;
  }
  if (a < 16u) {
  if (!(((b | a) >= b))) r3 = 85u; else r3 = 143u;
  s += r3;
  }
  if (a < 15u) {
  r3 = 1u; if (b < 9u) r3 = 2u; if (b < 9u) r3 = 9u;
  s += r3;
  }
  return s;
}

unsigned f122(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  if (b < 21u) r1 = 4u; else r1 = 186u;
  s += r1;
  if (b < 20u) r1 = 82u; else r1 = 173u;
  s += r1;
  if (b < 7u) {
  if (((a * (a + 1u)) & 1u) == 0u) r3 = 109u; else r3 = 52u;
  s += r3;
  }
  if (a < 18u) {
  r2 = 1u; if (b < 23u) r2 = 2u; if (b < 23u) r2 = 9u;
  s += r2;
  }
  return s;
}

unsigned f123(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  r2 = 1u; if (a < 14u) r2 = 2u; if (a < 14u) r2 = 9u;
  s += r2;
  if (((b * b) & 3u) != 2u) r3 = 148u; else r3 = 55u;
  s += r3;
  if (b < 26u) {
  if (a == 25u) r3 = 150u; else r3 = 53u;
  s += r3;
  }
  if (b < 5u) {
  i = 0u; do { i = i + 1u; s = s + i; } while (i < 3u);
  }
  if (a == 0u) r3 = 140u; else r3 = 40u;
  s += r3;
  if (b < 27u) {
  r1 = 1u; if (b < 22u) r1 = 2u; if (b < 22u) r1 = 9u;
  s += r1;
  }
  if (b < 10u) {
  if (a < 20u) r2 = 7u; else r2 = 122u;
  s += r2;
  }
  r0 = 56u;
  s += r0;
  return s;
}

unsigned f124(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  if (a == 9u && b == 5u) r1 = 159u; else r1 = 84u;
  s += r1;
  if (a < 14u) {
  if (b < 20u) r1 = 35u; else r1 = 157u;
  s += r1;
  }
  if (b < 25u) {
  if (((b | a) >= b)) r1 = 124u; else r1 = 43u;
  s += r1;
  }
  if (b < 23u) {
  r1 = 45u;
  s += r1;
  }
  return s;
}

unsigned f125(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  r2 = 1u; if (b < 10u) r2 = 2u; if (b < 10u) r2 = 9u;
  s += r2;
  if (a < 25u) {
  if (((a * a) & 3u) != 2u) r1 = 144u; else r1 = 16u;
  s += r1;
  }
  if (a < 8u) {
  if (b < 9u) r3 = 91u; else r3 = 165u;
  s += r3;
  }
  if (((b * b) & 3u) != 2u) r3 = 124u; else r3 = 14u;
  s += r3;
  if (a < 19u) {
  if (((a | b) >= a)) r1 = 126u; else r1 = 37u;
  s += r1;
  }
  if (b < 19u) r0 = 8u; else r0 = 163u;
  s += r0;
  if (a == 23u && b == 9u) r2 = 134u; else r2 = 22u;
  s += r2;
  if (((a * a) & 3u) != 2u) r2 = 152u; else r2 = 85u;
  s += r2;
  return s;
}

unsigned f126(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  if (b < 17u) r3 = 93u; else r3 = 191u;
  s += r3;
  r3 = 1u; if (b < 14u) r3 = 2u; if (b < 14u) r3 = 9u;
  s += r3;
  if (a < 10u) {
  if (!(((a * (a + 1u)) & 1u) == 0u)) r3 = 9u; else r3 = 192u;
  s += r3;
  }
  if (((a & b) <= b)) r3 = 168u; else r3 = 2u;
  s += r3;
  return s;
}

unsigned f127(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  if (((b * (b + 1u)) & 1u) == 0u) r2 = 175u; else r2 = 6u;
  s += r2;
  if (((b & a) <= a)) r1 = 137u; else r1 = 65u;
  s += r1;
  if (b < 19u) r2 = 44u; else r2 = 160u;
  s += r2;
  if (a < 4u) {
  r2 = 1u; if (a < 13u) r2 = 2u; if (a < 13u) r2 = 9u;
  s += r2;
  }
  if (a < 20u) {
  i = 0u; do { i = i + 1u; s = s + i; } while (i < 4u);
  }
  if (b < 22u) r2 = 62u; else r2 = 197u;
  s += r2;
  return s;
}

unsigned f128(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  if (((a | b) >= a)) r0 = 114u; else r0 = 78u;
  s += r0;
  if (a < 9u) {
  if (a < 11u) r0 = 22u; else r0 = 148u;
  s += r0;
  }
  if (a == 10u) r0 = 181u; else r0 = 58u;
  s += r0;
  i = 0u; do { i = i + 1u; s = s + i; } while (i < 3u);
  if (a < 8u) {
  if (a == 22u && b == 7u) r2 = 114u; else r2 = 5u;
  s += r2;
  }
  return s;
}

unsigned f129(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  if (b < 21u) {
  if (b < 25u) r0 = 43u; else r0 = 103u;
  s += r0;
  }
  if (b < 4u) {
  i = 0u; do { i = i + 1u; s = s + i; } while (i < 4u);
  }
  r3 = 1u; if (a < 21u) r3 = 2u; if (a < 21u) r3 = 9u;
  s += r3;
  if (a < 7u) {
  if (((b * (b + 1u)) & 1u) == 0u) r2 = 101u; else r2 = 89u;
  s += r2;
  }
  if (a < 4u) {
  if (a == 10u && b == 30u) r3 = 108u; else r3 = 72u;
  s += r3;
  }
  return s;
}

unsigned f130(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  r3 = 1u; if (b < 18u) r3 = 2u; if (b < 18u) r3 = 9u;
  s += r3;
  if (!(((a | b) >= a))) r2 = 65u; else r2 = 145u;
  s += r2;
  if (b < 9u) {
  if (!(((a * a) & 3u) != 2u)) r0 = 54u; else r0 = 198u;
  s += r0;
  }
  if (((b * (b + 1u)) & 1u) == 0u) r0 = 110u; else r0 = 78u;
  s += r0;
  i = 0u; do { i = i + 1u; s = s + i; } while (i < 5u);
  r2 = 1u; if (b < 8u) r2 = 2u; if (b < 8u) r2 = 9u;
  s += r2;
  r1 = 1u; if (a < 14u) r1 = 2u; if (a < 14u) r1 = 9u;
  s += r1;
  return s;
}

unsigned f131(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  r3 = 1u; if (a < 9u) r3 = 2u; if (a < 9u) r3 = 9u;
  s += r3;
  if (a < 13u) r2 = 35u; else r2 = 193u;
  s += r2;
  if (!(((a & b) <= b))) r3 = 16u; else r3 = 155u;
  s += r3;
  if (!(((a * a) & 3u) != 2u)) r0 = 55u; else r0 = 132u;
  s += r0;
  return s;
}

unsigned f132(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  r3 = 1u; if (a < 10u) r3 = 2u; if (a < 10u) r3 = 9u;
  s += r3;
  if (a < 14u) {
  if (a == 0u) r0 = 193u; else r0 = 91u;
  s += r0;
  }
  if (!(((a & b) <= b))) r0 = 24u; else r0 = 115u;
  s += r0;
  if (a < 8u) {
  if (a == 3u && b == 11u) r0 = 180u; else r0 = 35u;
  s += r0;
  }
  if (a < 21u) {
  r1 = 1u; if (b < 21u) r1 = 2u; if (b < 21u) r1 = 9u;
  s += r1;
  }
  if (!(((b * b) & 3u) != 2u)) r1 = 49u; else r1 = 190u;
  s += r1;
  if (b < 27u) {
  if (a < 12u) r3 = 23u; else r3 = 136u;
  s += r3;
  }
  r1 = 1u; if (a < 14u) r1 = 2u; if (a < 14u) r1 = 9u;
  s += r1;
  return s;
}

unsigned f133(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  i = 0u; do { i = i + 1u; s = s + i; } while (i < 5u);
  if (a < 8u) {
  r3 = 46u;
  s += r3;
  }
  if (b < 13u) {
  r2 = 1u; if (a < 18u) r2 = 2u; if (a < 18u) r2 = 9u;
  s += r2;
  }
  if (b < 20u) {
  i = 0u; do { i = i + 1u; s = s + i; } while (i < 2u);
  }
  if (a == 20u && b == 23u) r0 = 180u; else r0 = 30u;
  s += r0;
  i = 0u; do { i = i + 1u; s = s + i; } while (i < 3u);
  return s;
}

unsigned f134(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  if (b < 21u) r3 = 16u; else r3 = 136u;
  s += r3;
  if (b < 8u) {
  i = 0u; do { i = i + 1u; s = s + i; } while (i < 5u);
  }
  if (((b & a) <= a)) r3 = 188u; else r3 = 4u;
  s += r3;
  if (b < 4u) {
  if (a == 14u) r2 = 149u; else r2 = 12u;
  s += r2;
  }
  if (b < 16u) r0 = 55u; else r0 = 163u;
  s += r0;
  if (b < 9u) {
  if (a < 7u) r2 = 48u; else r2 = 167u;
  s += r2;
  }
  if (a < 5u) {
  r3 = 1u; if (b < 14u) r3 = 2u; if (b < 14u) r3 = 9u;
  s += r3;
  }
  return s;
}

unsigned f135(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  if (!(((a | b) >= a))) r1 = 77u; else r1 = 196u;
  s += r1;
  if (b < 6u) r1 = 93u; else r1 = 152u;
  s += r1;
  r0 = 1u; if (b < 20u) r0 = 2u; if (b < 20u) r0 = 9u;
  s += r0;
  i = 0u; do { i = i + 1u; s = s + i; } while (i < 5u);
  if (a == 25u) r1 = 153u; else r1 = 67u;
  s += r1;
  r1 = 1u; if (a < 17u) r1 = 2u; if (a < 17u) r1 = 9u;
  s += r1;
  return s;
}

unsigned f136(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  if (!(((a * a) & 3u) != 2u)) r3 = 50u; else r3 = 147u;
  s += r3;
  if (((a | b) >= a)) r2 = 109u; else r2 = 12u;
  s += r2;
  r2 = 1u; if (b < 16u) r2 = 2u; if (b < 16u) r2 = 9u;
  s += r2;
  if (b < 27u) {
  i = 0u; do { i = i + 1u; s = s + i; } while (i < 4u);
  }
  if (!(((b * b) & 3u) != 2u)) r0 = 23u; else r0 = 133u;
  s += r0;
  if (!(((b * (b + 1u)) & 1u) == 0u)) r2 = 9u; else r2 = 191u;
  s += r2;
  return s;
}

unsigned f137(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  if (a == 17u && b == 18u) r3 = 152u; else r3 = 81u;
  s += r3;
  r0 = 1u; if (a < 18u) r0 = 2u; if (a < 18u) r0 = 9u;
  s += r0;
  if (((a * a) & 3u) != 2u) r2 = 123u; else r2 = 44u;
  s += r2;
  r1 = 1u; if (b < 8u) r1 = 2u; if (b < 8u) r1 = 9u;
  s += r1;
  if (a < 12u) {
  if (((a * (a + 1u)) & 1u) == 0u) r3 = 155u; else r3 = 56u;
  s += r3;
  }
  if (a < 26u) {
  r3 = 1u; if (b < 21u) r3 = 2u; if (b < 21u) r3 = 9u;
  s += r3;
  }
  r0 = 1u; if (a < 22u) r0 = 2u; if (a < 22u) r0 = 9u;
  s += r0;
  return s;
}

unsigned f138(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  if (((b & a) <= a)) r3 = 148u; else r3 = 80u;
  s += r3;
  i = 0u; do { i = i + 1u; s = s + i; } while (i < 2u);
  r2 = 1u; if (a < 21u) r2 = 2u; if (a < 21u) r2 = 9u;
  s += r2;
  if (!(((a * a) & 3u) != 2u)) r1 = 47u; else r1 = 164u;
  s += r1;
  return s;
}

unsigned f139(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  if (b < 16u) r0 = 62u; else r0 = 119u;
  s += r0;
  if (((a & b) <= b)) r2 = 190u; else r2 = 9u;
  s += r2;
  r0 = 1u; if (b < 10u) r0 = 2u; if (b < 10u) r0 = 9u;
  s += r0;
  i = 0u; do { i = i + 1u; s = s + i; } while (i < 2u);
  if (((a | b) >= a)) r2 = 184u; else r2 = 6u;
  s += r2;
  if (b < 13u) {
  r1 = 1u; if (a < 20u) r1 = 2u; if (a < 20u) r1 = 9u;
  s += r1;
  }
  if (b < 17u) {
  r0 = 99u;
  s += r0;
  }
  if (b < 15u) r2 = 38u; else r2 = 165u;
  s += r2;
  return s;
}

unsigned f140(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  if (a < 24u) {
  if (!(((b | a) >= b))) r3 = 80u; else r3 = 110u;
  s += r3;
  }
  if (b < 8u) {
  if (a < 13u) r3 = 61u; else r3 = 136u;
  s += r3;
  }
  if (!(((a & b) <= b))) r1 = 25u; else r1 = 194u;
  s += r1;
  if (a == 24u) r2 = 160u; else r2 = 10u;
  s += r2;
  return s;
}

unsigned f141(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  if (b < 16u) {
  if (a < 22u) r0 = 22u; else r0 = 198u;
  s += r0;
  }
  r3 = 1u; if (b < 15u) r3 = 2u; if (b < 15u) r3 = 9u;
  s += r3;
  r1 = 1u; if (a < 22u) r1 = 2u; if (a < 22u) r1 = 9u;
  s += r1;
  if (a < 16u) r3 = 34u; else r3 = 163u;
  s += r3;
  return s;
}

unsigned f142(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  if (!(((a * (a + 1u)) & 1u) == 0u)) r2 = 64u; else r2 = 107u;
  s += r2;
  r3 = 1u; if (a < 11u) r3 = 2u; if (a < 11u) r3 = 9u;
  s += r3;
  if (b < 12u) {
  if (!(((a * a) & 3u) != 2u)) r1 = 85u; else r1 = 197u;
  s += r1;
  }
  if (((a | b) >= a)) r3 = 184u; else r3 = 35u;
  s += r3;
  if (a == 14u) r0 = 155u; else r0 = 3u;
  s += r0;
  if (a < 10u) {
  if (((a * a) & 3u) != 2u) r0 = 166u; else r0 = 43u;
  s += r0;
  }
  return s;
}

unsigned f143(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  if (b < 27u) {
  r0 = 1u; if (a < 11u) r0 = 2u; if (a < 11u) r0 = 9u;
  s += r0;
  }
  if (a < 11u) {
  i = 0u; do { i = i + 1u; s = s + i; } while (i < 6u);
  }
  if (b < 11u) {
  i = 0u; do { i = i + 1u; s = s + i; } while (i < 4u);
  }
  if (a < 15u) {
  r1 = 1u; if (b < 14u) r1 = 2u; if (b < 14u) r1 = 9u;
  s += r1;
  }
  if (b < 21u) {
  if (!(((b * b) & 3u) != 2u)) r0 = 86u; else r0 = 170u;
  s += r0;
  }
  return s;
}

unsigned f144(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  if (a == 8u) r3 = 148u; else r3 = 1u;
  s += r3;
  if (b < 6u) {
  if (!(((b | a) >= b))) r2 = 53u; else r2 = 145u;
  s += r2;
  }
  if (!(((b | a) >= b))) r3 = 92u; else r3 = 147u;
  s += r3;
  i = 0u; do { i = i + 1u; s = s + i; } while (i < 3u);
  i = 0u; do { i = i + 1u; s = s + i; } while (i < 2u);
  if (a < 17u) r3 = 65u; else r3 = 199u;
  s += r3;
  if (b < 19u) {
  r0 = 1u; if (b < 8u) r0 = 2u; if (b < 8u) r0 = 9u;
  s += r0;
  }
  r2 = 1u; if (a < 19u) r2 = 2u; if (a < 19u) r2 = 9u;
  s += r2;
  return s;
}

unsigned f145(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  if (a < 4u) {
  i = 0u; do { i = i + 1u; s = s + i; } while (i < 3u);
  }
  if (a < 7u) r3 = 8u; else r3 = 100u;
  s += r3;
  if (b < 14u) {
  r1 = 1u; if (b < 11u) r1 = 2u; if (b < 11u) r1 = 9u;
  s += r1;
  }
  if (a == 11u && b == 23u) r1 = 156u; else r1 = 50u;
  s += r1;
  if (a < 23u) {
  if (!(((b * (b + 1u)) & 1u) == 0u)) r1 = 76u; else r1 = 135u;
  s += r1;
  }
  return s;
}

unsigned f146(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  r0 = 87u;
  s += r0;
  r0 = 30u;
  s += r0;
  if (b < 14u) r0 = 42u; else r0 = 114u;
  s += r0;
  if (!(((b | a) >= b))) r3 = 4u; else r3 = 103u;
  s += r3;
  if (b < 17u) {
  if (a == 9u) r0 = 111u; else r0 = 25u;
  s += r0;
  }
  if (((a & b) <= b)) r2 = 156u; else r2 = 47u;
  s += r2;
  if (a < 14u) {
  r0 = 1u; if (a < 16u) r0 = 2u; if (a < 16u) r0 = 9u;
  s += r0;
  }
  return s;
}

unsigned f147(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  r3 = 1u; if (a < 19u) r3 = 2u; if (a < 19u) r3 = 9u;
  s += r3;
  r3 = 22u;
  s += r3;
  if (((a * a) & 3u) != 2u) r3 = 189u; else r3 = 4u;
  s += r3;
  if (b < 22u) {
  r1 = 1u; if (b < 22u) r1 = 2u; if (b < 22u) r1 = 9u;
  s += r1;
  }
  return s;
}

unsigned f148(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  if (a < 8u) {
  r2 = 1u; if (a < 18u) r2 = 2u; if (a < 18u) r2 = 9u;
  s += r2;
  }
  if (a < 14u) {
  i = 0u; do { i = i + 1u; s = s + i; } while (i < 4u);
  }
  if (b < 23u) {
  if (((b | a) >= b)) r3 = 100u; else r3 = 75u;
  s += r3;
  }
  if (b < 19u) {
  r0 = 1u; if (a < 17u) r0 = 2u; if (a < 17u) r0 = 9u;
  s += r0;
  }
  return s;
}

unsigned f149(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  if (b < 4u) {
  if (a == 5u) r0 = 148u; else r0 = 54u;
  s += r0;
  }
  r3 = 1u; if (b < 10u) r3 = 2u; if (b < 10u) r3 = 9u;
  s += r3;
  if (!(((b & a) <= a))) r0 = 44u; else r0 = 172u;
  s += r0;
  if (a < 9u) {
  if (((a | b) >= a)) r1 = 171u; else r1 = 38u;
  s += r1;
  }
  if (b < 21u) {
  if (a == 31u && b == 21u) r2 = 181u; else r2 = 71u;
  s += r2;
  }
  i = 0u; do { i = i + 1u; s = s + i; } while (i < 2u);
  if (b < 4u) {
  r0 = 1u; if (a < 16u) r0 = 2u; if (a < 16u) r0 = 9u;
  s += r0;
  }
  if (!(((b * (b + 1u)) & 1u) == 0u)) r1 = 31u; else r1 = 144u;
  s += r1;
  return s;
}

unsigned f150(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  if (a < 7u) r1 = 40u; else r1 = 156u;
  s += r1;
  if (a < 14u) r2 = 48u; else r2 = 136u;
  s += r2;
  if (a < 6u) r3 = 25u; else r3 = 186u;
  s += r3;
  if (!(((a & b) <= b))) r2 = 7u; else r2 = 189u;
  s += r2;
  return s;
}

unsigned f151(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  r3 = 1u; if (a < 12u) r3 = 2u; if (a < 12u) r3 = 9u;
  s += r3;
  i = 0u; do { i = i + 1u; s = s + i; } while (i < 5u);
  if (b < 25u) {
  r2 = 23u;
  s += r2;
  }
  r3 = 1u; if (b < 10u) r3 = 2u; if (b < 10u) r3 = 9u;
  s += r3;
  r2 = 1u; if (b < 13u) r2 = 2u; if (b < 13u) r2 = 9u;
  s += r2;
  return s;
}

unsigned f152(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  r1 = 1u; if (b < 17u) r1 = 2u; if (b < 17u) r1 = 9u;
  s += r1;
  r2 = 1u; if (a < 15u) r2 = 2u; if (a < 15u) r2 = 9u;
  s += r2;
  if (b < 21u) {
  if (!(((a * a) & 3u) != 2u)) r1 = 29u; else r1 = 183u;
  s += r1;
  }
  if (!(((a | b) >= a))) r3 = 40u; else r3 = 177u;
  s += r3;
  if (a < 11u) r1 = 18u; else r1 = 115u;
  s += r1;
  if (!(((b & a) <= a))) r3 = 95u; else r3 = 152u;
  s += r3;
  if (b < 9u) {
  if (!(((b * b) & 3u) != 2u)) r2 = 83u; else r2 = 143u;
  s += r2;
  }
  return s;
}

unsigned f153(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  if (a == 15u) r0 = 160u; else r0 = 55u;
  s += r0;
  if (b < 22u) r2 = 96u; else r2 = 159u;
  s += r2;
  r2 = 44u;
  s += r2;
  if (a < 10u) {
  r1 = 36u;
  s += r1;
  }
  if (((a * (a + 1u)) & 1u) == 0u) r3 = 180u; else r3 = 84u;
  s += r3;
  if (a < 11u) {
  if (a < 16u) r3 = 30u; else r3 = 144u;
  s += r3;
  }
  r3 = 1u; if (a < 17u) r3 = 2u; if (a < 17u) r3 = 9u;
  s += r3;
  return s;
}

unsigned f154(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  if (((a & b) <= b)) r1 = 158u; else r1 = 82u;
  s += r1;
  r3 = 1u; if (a < 11u) r3 = 2u; if (a < 11u) r3 = 9u;
  s += r3;
  r3 = 54u;
  s += r3;
  r3 = 1u; if (b < 11u) r3 = 2u; if (b < 11u) r3 = 9u;
  s += r3;
  r1 = 1u; if (a < 11u) r1 = 2u; if (a < 11u) r1 = 9u;
  s += r1;
  return s;
}

unsigned f155(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  if (!(((a * a) & 3u) != 2u)) r0 = 95u; else r0 = 197u;
  s += r0;
  if (b < 9u) {
  if (a == 22u && b == 18u) r2 = 194u; else r2 = 63u;
  s += r2;
  }
  if (b < 25u) r1 = 7u; else r1 = 145u;
  s += r1;
  i = 0u; do { i = i + 1u; s = s + i; } while (i < 2u);
  return s;
}

unsigned f156(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  r0 = 1u; if (b < 18u) r0 = 2u; if (b < 18u) r0 = 9u;
  s += r0;
  if (a < 13u) {
  if (!(((b * b) & 3u) != 2u)) r0 = 75u; else r0 = 154u;
  s += r0;
  }
  r3 = 30u;
  s += r3;
  if (b < 25u) {
  r3 = 1u; if (b < 11u) r3 = 2u; if (b < 11u) r3 = 9u;
  s += r3;
  }
  if (((b * b) & 3u) != 2u) r2 = 126u; else r2 = 65u;
  s += r2;
  r0 = 67u;
  s += r0;
  return s;
}

unsigned f157(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  r3 = 1u; if (a < 22u) r3 = 2u; if (a < 22u) r3 = 9u;
  s += r3;
  if (b < 27u) {
  if (((b * (b + 1u)) & 1u) == 0u) r2 = 171u; else r2 = 11u;
  s += r2;
  }
  if (a < 23u) {
  if (a == 14u) r0 = 143u; else r0 = 54u;
  s += r0;
  }
  if (b < 11u) {
  if (((a * a) & 3u) != 2u) r2 = 158u; else r2 = 6u;
  s += r2;
  }
  return s;
}

unsigned f158(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  if (b < 27u) {
  r0 = 1u; if (a < 11u) r0 = 2u; if (a < 11u) r0 = 9u;
  s += r0;
  }
  if (!(((b * b) & 3u) != 2u)) r1 = 45u; else r1 = 154u;
  s += r1;
  if (b < 9u) {
  if (b < 24u) r3 = 25u; else r3 = 143u;
  s += r3;
  }
  r2 = 1u; if (b < 22u) r2 = 2u; if (b < 22u) r2 = 9u;
  s += r2;
  return s;
}

unsigned f159(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  if (a == 4u && b == 14u) r2 = 139u; else r2 = 34u;
  s += r2;
  if (a < 12u) {
  if (!(((b * b) & 3u) != 2u)) r1 = 85u; else r1 = 197u;
  s += r1;
  }
  i = 0u; do { i = i + 1u; s = s + i; } while (i < 5u);
  if (b < 15u) {
  if (((a & b) <= b)) r0 = 168u; else r0 = 36u;
  s += r0;
  }
  return s;
}

unsigned f160(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  if (b < 14u) {
  r0 = 1u; if (a < 12u) r0 = 2u; if (a < 12u) r0 = 9u;
  s += r0;
  }
  r1 = 1u; if (a < 18u) r1 = 2u; if (a < 18u) r1 = 9u;
  s += r1;
  if (a == 20u) r0 = 145u; else r0 = 43u;
  s += r0;
  if (a < 6u) {
  if (b < 14u) r2 = 11u; else r2 = 114u;
  s += r2;
  }
  if (a < 10u) {
  r2 = 1u; if (b < 19u) r2 = 2u; if (b < 19u) r2 = 9u;
  s += r2;
  }
  if (b < 8u) {
  r1 = 1u; if (a < 13u) r1 = 2u; if (a < 13u) r1 = 9u;
  s += r1;
  }
  if (a < 6u) {
  if (((b & a) <= a)) r2 = 142u; else r2 = 88u;
  s += r2;
  }
  if (b < 11u) {
  r3 = 1u; if (b < 12u) r3 = 2u; if (b < 12u) r3 = 9u;
  s += r3;
  }
  return s;
}

unsigned f161(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  if (((a & b) <= b)) r3 = 187u; else r3 = 66u;
  s += r3;
  if (((b * b) & 3u) != 2u) r2 = 147u; else r2 = 91u;
  s += r2;
  if (b < 14u) {
  if (b < 23u) r1 = 35u; else r1 = 195u;
  s += r1;
  }
  if (b < 22u) {
  if (a == 2u && b == 11u) r3 = 181u; else r3 = 71u;
  s += r3;
  }
  if (((a & b) <= b)) r1 = 167u; else r1 = 33u;
  s += r1;
  if (a < 14u) {
  r0 = 1u; if (b < 15u) r0 = 2u; if (b < 15u) r0 = 9u;
  s += r0;
  }
  return s;
}

unsigned f162(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  if (b < 16u) {
  r3 = 93u;
  s += r3;
  }
  if (a < 21u) r1 = 30u; else r1 = 140u;
  s += r1;
  r2 = 72u;
  s += r2;
  r2 = 1u; if (a < 11u) r2 = 2u; if (a < 11u) r2 = 9u;
  s += r2;
  return s;
}

unsigned f163(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  if (a == 0u && b == 1u) r2 = 151u; else r2 = 5u;
  s += r2;
  r2 = 68u;
  s += r2;
  if (b < 14u) {
  r2 = 1u; if (a < 8u) r2 = 2u; if (a < 8u) r2 = 9u;
  s += r2;
  }
  if (a == 20u && b == 14u) r2 = 106u; else r2 = 34u;
  s += r2;
  if (b < 8u) r3 = 37u; else r3 = 131u;
  s += r3;
  return s;
}

unsigned f164(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  if (a < 7u) {
  r2 = 1u; if (a < 12u) r2 = 2u; if (a < 12u) r2 = 9u;
  s += r2;
  }
  if (((b & a) <= a)) r0 = 156u; else r0 = 80u;
  s += r0;
  if (b < 19u) r3 = 8u; else r3 = 112u;
  s += r3;
  if (b < 14u) {
  if (((a & b) <= b)) r3 = 169u; else r3 = 99u;
  s += r3;
  }
  if (((b * (b + 1u)) & 1u) == 0u) r0 = 102u; else r0 = 13u;
  s += r0;
  return s;
}

unsigned f165(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  r2 = 1u; if (b < 19u) r2 = 2u; if (b < 19u) r2 = 9u;
  s += r2;
  if (a == 13u) r0 = 159u; else r0 = 60u;
  s += r0;
  if (((b * (b + 1u)) & 1u) == 0u) r2 = 175u; else r2 = 56u;
  s += r2;
  if (b < 11u) {
  if (a == 9u && b == 13u) r1 = 166u; else r1 = 37u;
  s += r1;
  }
  if (a < 18u) {
  r2 = 42u;
  s += r2;
  }
  if (b < 22u) {
  r2 = 1u; if (b < 23u) r2 = 2u; if (b < 23u) r2 = 9u;
  s += r2;
  }
  return s;
}

unsigned f166(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  r1 = 1u; if (a < 22u) r1 = 2u; if (a < 22u) r1 = 9u;
  s += r1;
  if (a < 7u) r1 = 63u; else r1 = 185u;
  s += r1;
  if (b < 14u) r2 = 79u; else r2 = 169u;
  s += r2;
  if (!(((b | a) >= b))) r2 = 6u; else r2 = 111u;
  s += r2;
  if (a < 22u) {
  i = 0u; do { i = i + 1u; s = s + i; } while (i < 3u);
  }
  if (a == 23u && b == 11u) r1 = 145u; else r1 = 10u;
  s += r1;
  if (b < 11u) {
  i = 0u; do { i = i + 1u; s = s + i; } while (i < 3u);
  }
  return s;
}

unsigned f167(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  r1 = 76u;
  s += r1;
  if (a < 4u) {
  if (a == 23u) r2 = 115u; else r2 = 87u;
  s += r2;
  }
  if (b < 5u) {
  if (a < 11u) r1 = 30u; else r1 = 193u;
  s += r1;
  }
  if (a == 21u) r0 = 171u; else r0 = 77u;
  s += r0;
  if (b < 25u) {
  if (a < 22u) r1 = 96u; else r1 = 108u;
  s += r1;
  }
  return s;
}

unsigned f168(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  if (((a * a) & 3u) != 2u) r3 = 176u; else r3 = 78u;
  s += r3;
  if (((b | a) >= b)) r0 = 132u; else r0 = 58u;
  s += r0;
  r2 = 1u; if (b < 8u) r2 = 2u; if (b < 8u) r2 = 9u;
  s += r2;
  if (!(((b | a) >= b))) r0 = 7u; else r0 = 180u;
  s += r0;
  if (!(((b * b) & 3u) != 2u)) r2 = 44u; else r2 = 131u;
  s += r2;
  return s;
}

unsigned f169(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  if (b < 22u) {
  if (b < 14u) r1 = 82u; else r1 = 185u;
  s += r1;
  }
  if (b < 26u) {
  if (((a & b) <= b)) r3 = 174u; else r3 = 14u;
  s += r3;
  }
  if (((b | a) >= b)) r2 = 173u; else r2 = 61u;
  s += r2;
  r0 = 65u;
  s += r0;
  if (a == 11u && b == 15u) r2 = 151u; else r2 = 92u;
  s += r2;
  if (b < 5u) {
  if (b < 20u) r0 = 89u; else r0 = 181u;
  s += r0;
  }
  if (a == 0u && b == 24u) r2 = 196u; else r2 = 51u;
  s += r2;
  if (b < 26u) {
  if (((a * (a + 1u)) & 1u) == 0u) r1 = 128u; else r1 = 71u;
  s += r1;
  }
  return s;
}

unsigned f170(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  i = 0u; do { i = i + 1u; s = s + i; } while (i < 2u);
  if (b < 10u) {
  if (a < 12u) r0 = 1u; else r0 = 140u;
  s += r0;
  }
  if (a < 19u) {
  if (!(((b | a) >= b))) r1 = 91u; else r1 = 197u;
  s += r1;
  }
  if (b < 6u) {
  if (((a * (a + 1u)) & 1u) == 0u) r0 = 160u; else r0 = 2u;
  s += r0;
  }
  return s;
}

unsigned f171(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  r2 = 1u; if (a < 22u) r2 = 2u; if (a < 22u) r2 = 9u;
  s += r2;
  if (((b & a) <= a)) r0 = 127u; else r0 = 42u;
  s += r0;
  if (((a | b) >= a)) r2 = 129u; else r2 = 99u;
  s += r2;
  if (!(((a * a) & 3u) != 2u)) r0 = 14u; else r0 = 140u;
  s += r0;
  if (a == 29u) r2 = 167u; else r2 = 45u;
  s += r2;
  return s;
}

unsigned f172(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  r2 = 1u; if (a < 19u) r2 = 2u; if (a < 19u) r2 = 9u;
  s += r2;
  r0 = 1u; if (b < 9u) r0 = 2u; if (b < 9u) r0 = 9u;
  s += r0;
  r0 = 19u;
  s += r0;
  if (b < 12u) {
  if (a < 13u) r2 = 3u; else r2 = 167u;
  s += r2;
  }
  if (a < 8u) r0 = 8u; else r0 = 166u;
  s += r0;
  return s;
}

unsigned f173(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  if (((a * (a + 1u)) & 1u) == 0u) r0 = 106u; else r0 = 25u;
  s += r0;
  if (b < 24u) {
  if (((a * a) & 3u) != 2u) r3 = 102u; else r3 = 26u;
  s += r3;
  }
  if (a < 15u) {
  r1 = 1u; if (b < 19u) r1 = 2u; if (b < 19u) r1 = 9u;
  s += r1;
  }
  if (b < 22u) {
  i = 0u; do { i = i + 1u; s = s + i; } while (i < 2u);
  }
  if (b < 22u) {
  if (a < 13u) r1 = 47u; else r1 = 135u;
  s += r1;
  }
  return s;
}

unsigned f174(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  r1 = 1u; if (a < 10u) r1 = 2u; if (a < 10u) r1 = 9u;
  s += r1;
  if (b < 12u) {
  if (!(((b * b) & 3u) != 2u)) r0 = 59u; else r0 = 105u;
  s += r0;
  }
  r1 = 85u;
  s += r1;
  if (!(((a * (a + 1u)) & 1u) == 0u)) r3 = 15u; else r3 = 159u;
  s += r3;
  if (a == 24u && b == 19u) r0 = 162u; else r0 = 14u;
  s += r0;
  if (b < 19u) {
  if (a < 6u) r1 = 84u; else r1 = 187u;
  s += r1;
  }
  r0 = 92u;
  s += r0;
  if (((b * (b + 1u)) & 1u) == 0u) r3 = 133u; else r3 = 99u;
  s += r3;
  return s;
}

unsigned f175(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  r1 = 1u; if (a < 8u) r1 = 2u; if (a < 8u) r1 = 9u;
  s += r1;
  if (b < 15u) {
  if (((b * (b + 1u)) & 1u) == 0u) r2 = 128u; else r2 = 1u;
  s += r2;
  }
  if (a < 11u) r2 = 5u; else r2 = 100u;
  s += r2;
  if (a < 13u) {
  if (((b & a) <= a)) r3 = 133u; else r3 = 59u;
  s += r3;
  }
  if (a < 24u) {
  if (a < 15u) r0 = 61u; else r0 = 170u;
  s += r0;
  }
  i = 0u; do { i = i + 1u; s = s + i; } while (i < 5u);
  if (a < 22u) {
  if (((a & b) <= b)) r1 = 109u; else r1 = 58u;
  s += r1;
  }
  return s;
}

unsigned f176(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  if (a < 5u) {
  if (a == 10u) r2 = 184u; else r2 = 14u;
  s += r2;
  }
  if (b < 26u) {
  i = 0u; do { i = i + 1u; s = s + i; } while (i < 2u);
  }
  if (a < 5u) {
  if (a == 3u && b == 18u) r2 = 166u; else r2 = 70u;
  s += r2;
  }
  if (b < 8u) {
  if (b < 19u) r2 = 11u; else r2 = 188u;
  s += r2;
  }
  if (a < 22u) {
  if (a == 3u && b == 31u) r3 = 124u; else r3 = 6u;
  s += r3;
  }
  r0 = 1u; if (a < 10u) r0 = 2u; if (a < 10u) r0 = 9u;
  s += r0;
  return s;
}

unsigned f177(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  if (a < 5u) {
  if (((a * (a + 1u)) & 1u) == 0u) r0 = 197u; else r0 = 45u;
  s += r0;
  }
  i = 0u; do { i = i + 1u; s = s + i; } while (i < 6u);
  if (((b & a) <= a)) r0 = 163u; else r0 = 74u;
  s += r0;
  if (b < 10u) {
  i = 0u; do { i = i + 1u; s = s + i; } while (i < 3u);
  }
  if (!(((b * (b + 1u)) & 1u) == 0u)) r0 = 13u; else r0 = 177u;
  s += r0;
  return s;
}

unsigned f178(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  if (a < 24u) r3 = 37u; else r3 = 154u;
  s += r3;
  if (!(((a * a) & 3u) != 2u)) r3 = 17u; else r3 = 190u;
  s += r3;
  r3 = 34u;
  s += r3;
  if (a == 26u) r0 = 152u; else r0 = 18u;
  s += r0;
  return s;
}

unsigned f179(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  if (a < 4u) {
  if (!(((a | b) >= a))) r2 = 52u; else r2 = 100u;
  s += r2;
  }
  r3 = 1u; if (b < 19u) r3 = 2u; if (b < 19u) r3 = 9u;
  s += r3;
  if (a < 9u) {
  r0 = 1u; if (b < 23u) r0 = 2u; if (b < 23u) r0 = 9u;
  s += r0;
  }
  i = 0u; do { i = i + 1u; s = s + i; } while (i < 5u);
  return s;
}

unsigned f180(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  if (a < 8u) {
  if (((b * b) & 3u) != 2u) r3 = 153u; else r3 = 90u;
  s += r3;
  }
  if (a == 1u && b == 29u) r1 = 191u; else r1 = 45u;
  s += r1;
  if (a == 11u && b == 24u) r0 = 150u; else r0 = 10u;
  s += r0;
  if (a < 11u) {
  r3 = 58u;
  s += r3;
  }
  if (a == 3u) r3 = 196u; else r3 = 42u;
  s += r3;
  i = 0u; do { i = i + 1u; s = s + i; } while (i < 5u);
  if (b < 18u) {
  if (b < 13u) r0 = 74u; else r0 = 195u;
  s += r0;
  }
  return s;
}

unsigned f181(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  if (a == 13u && b == 12u) r3 = 176u; else r3 = 70u;
  s += r3;
  if (b < 18u) {
  if (!(((a | b) >= a))) r3 = 43u; else r3 = 154u;
  s += r3;
  }
  i = 0u; do { i = i + 1u; s = s + i; } while (i < 6u);
  if (a < 18u) r1 = 81u; else r1 = 108u;
  s += r1;
  if (a < 5u) {
  if (a < 15u) r1 = 66u; else r1 = 178u;
  s += r1;
  }
  i = 0u; do { i = i + 1u; s = s + i; } while (i < 2u);
  if (b < 24u) {
  r0 = 1u; if (a < 22u) r0 = 2u; if (a < 22u) r0 = 9u;
  s += r0;
  }
  return s;
}

unsigned f182(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  if (b < 22u) {
  if (a == 20u && b == 13u) r2 = 125u; else r2 = 32u;
  s += r2;
  }
  r3 = 1u; if (b < 21u) r3 = 2u; if (b < 21u) r3 = 9u;
  s += r3;
  if (a < 8u) r2 = 5u; else r2 = 132u;
  s += r2;
  if (((a & b) <= b)) r1 = 124u; else r1 = 64u;
  s += r1;
  return s;
}

unsigned f183(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  if (a == 5u) r1 = 111u; else r1 = 45u;
  s += r1;
  r0 = 1u; if (b < 9u) r0 = 2u; if (b < 9u) r0 = 9u;
  s += r0;
  i = 0u; do { i = i + 1u; s = s + i; } while (i < 4u);
  if (a < 17u) {
  if (b < 8u) r1 = 2u; else r1 = 138u;
  s += r1;
  }
  if (a < 16u) {
  if (a == 13u && b == 19u) r3 = 143u; else r3 = 80u;
  s += r3;
  }
  if (((a & b) <= b)) r0 = 121u; else r0 = 35u;
  s += r0;
  return s;
}

unsigned f184(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  if (a < 9u) {
  if (!(((a | b) >= a))) r3 = 69u; else r3 = 171u;
  s += r3;
  }
  if (b < 27u) {
  if (((a | b) >= a)) r0 = 173u; else r0 = 56u;
  s += r0;
  }
  r2 = 1u; if (b < 14u) r2 = 2u; if (b < 14u) r2 = 9u;
  s += r2;
  if (a < 10u) {
  if (b < 11u) r3 = 40u; else r3 = 111u;
  s += r3;
  }
  if (!(((b * b) & 3u) != 2u)) r1 = 11u; else r1 = 148u;
  s += r1;
  if (!(((b | a) >= b))) r3 = 93u; else r3 = 181u;
  s += r3;
  if (a < 8u) {
  if (!(((a * a) & 3u) != 2u)) r2 = 42u; else r2 = 111u;
  s += r2;
  }
  if (a < 5u) {
  r3 = 1u;
  s += r3;
  }
  return s;
}

unsigned f185(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  i = 0u; do { i = i + 1u; s = s + i; } while (i < 2u);
  if (!(((a & b) <= b))) r0 = 86u; else r0 = 127u;
  s += r0;
  if (!(((a * (a + 1u)) & 1u) == 0u)) r1 = 67u; else r1 = 154u;
  s += r1;
  if (b < 4u) {
  if (!(((a * a) & 3u) != 2u)) r1 = 73u; else r1 = 187u;
  s += r1;
  }
  return s;
}

unsigned f186(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  if (b < 16u) {
  r1 = 29u;
  s += r1;
  }
  r2 = 1u; if (b < 9u) r2 = 2u; if (b < 9u) r2 = 9u;
  s += r2;
  if (a == 29u && b == 11u) r3 = 113u; else r3 = 26u;
  s += r3;
  if (b < 20u) {
  if (b < 14u) r1 = 82u; else r1 = 160u;
  s += r1;
  }
  if (((a * (a + 1u)) & 1u) == 0u) r1 = 180u; else r1 = 53u;
  s += r1;
  if (a < 10u) r0 = 85u; else r0 = 167u;
  s += r0;
  if (a < 26u) {
  if (a < 17u) r2 = 2u; else r2 = 151u;
  s += r2;
  }
  if (a < 17u) {
  r0 = 1u; if (b < 23u) r0 = 2u; if (b < 23u) r0 = 9u;
  s += r0;
  }
  return s;
}

unsigned f187(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  if (a < 19u) r1 = 41u; else r1 = 113u;
  s += r1;
  if (a < 12u) {
  if (b < 9u) r1 = 55u; else r1 = 116u;
  s += r1;
  }
  if (b < 27u) {
  r1 = 1u; if (a < 16u) r1 = 2u; if (a < 16u) r1 = 9u;
  s += r1;
  }
  if (b < 4u) {
  if (((b * b) & 3u) != 2u) r3 = 108u; else r3 = 54u;
  s += r3;
  }
  r2 = 78u;
  s += r2;
  if (!(((a * (a + 1u)) & 1u) == 0u)) r2 = 67u; else r2 = 144u;
  s += r2;
  if (b < 7u) {
  r3 = 71u;
  s += r3;
  }
  if (!(((b | a) >= b))) r1 = 22u; else r1 = 180u;
  s += r1;
  return s;
}

unsigned f188(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  r3 = 1u; if (a < 9u) r3 = 2u; if (a < 9u) r3 = 9u;
  s += r3;
  if (b < 11u) {
  if (a == 7u && b == 7u) r3 = 113u; else r3 = 11u;
  s += r3;
  }
  if (a < 11u) {
  if (!(((a * a) & 3u) != 2u)) r3 = 42u; else r3 = 143u;
  s += r3;
  }
  if (a < 13u) {
  if (((b * b) & 3u) != 2u) r3 = 175u; else r3 = 89u;
  s += r3;
  }
  if (a < 12u) r1 = 16u; else r1 = 126u;
  s += r1;
  r1 = 1u; if (b < 17u) r1 = 2u; if (b < 17u) r1 = 9u;
  s += r1;
  if (a < 4u) {
  r3 = 1u; if (b < 22u) r3 = 2u; if (b < 22u) r3 = 9u;
  s += r3;
  }
  if (((b | a) >= b)) r2 = 140u; else r2 = 25u;
  s += r2;
  return s;
}

unsigned f189(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  if (b < 26u) {
  r0 = 1u; if (a < 13u) r0 = 2u; if (a < 13u) r0 = 9u;
  s += r0;
  }
  if (b < 17u) {
  if (((b | a) >= b)) r1 = 102u; else r1 = 23u;
  s += r1;
  }
  r1 = 1u; if (a < 15u) r1 = 2u; if (a < 15u) r1 = 9u;
  s += r1;
  if (b < 19u) {
  if (b < 20u) r2 = 10u; else r2 = 169u;
  s += r2;
  }
  return s;
}

unsigned f190(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  if (a < 8u) r1 = 63u; else r1 = 176u;
  s += r1;
  if (a < 20u) r1 = 17u; else r1 = 167u;
  s += r1;
  if (a < 7u) {
  r3 = 1u; if (a < 20u) r3 = 2u; if (a < 20u) r3 = 9u;
  s += r3;
  }
  if (b < 24u) r3 = 23u; else r3 = 148u;
  s += r3;
  return s;
}

unsigned f191(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  r3 = 1u; if (b < 15u) r3 = 2u; if (b < 15u) r3 = 9u;
  s += r3;
  if (a < 12u) {
  r2 = 1u; if (b < 21u) r2 = 2u; if (b < 21u) r2 = 9u;
  s += r2;
  }
  if (b < 8u) r0 = 20u; else r0 = 129u;
  s += r0;
  if (b < 5u) {
  if (!(((a | b) >= a))) r2 = 71u; else r2 = 187u;
  s += r2;
  }
  if (b < 15u) {
  if (a < 23u) r0 = 36u; else r0 = 124u;
  s += r0;
  }
  if (b < 15u) {
  i = 0u; do { i = i + 1u; s = s + i; } while (i < 2u);
  }
  return s;
}

unsigned f192(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  i = 0u; do { i = i + 1u; s = s + i; } while (i < 4u);
  r3 = 1u; if (b < 22u) r3 = 2u; if (b < 22u) r3 = 9u;
  s += r3;
  if (((b * b) & 3u) != 2u) r3 = 156u; else r3 = 74u;
  s += r3;
  i = 0u; do { i = i + 1u; s = s + i; } while (i < 6u);
  if (!(((b * b) & 3u) != 2u)) r3 = 47u; else r3 = 173u;
  s += r3;
  if (!(((b & a) <= a))) r1 = 29u; else r1 = 103u;
  s += r1;
  if (a < 8u) {
  r0 = 1u; if (a < 19u) r0 = 2u; if (a < 19u) r0 = 9u;
  s += r0;
  }
  r1 = 1u; if (a < 10u) r1 = 2u; if (a < 10u) r1 = 9u;
  s += r1;
  return s;
}

unsigned f193(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  if (b < 16u) {
  if (((a & b) <= b)) r0 = 115u; else r0 = 70u;
  s += r0;
  }
  if (a == 18u) r0 = 100u; else r0 = 8u;
  s += r0;
  if (b < 7u) r2 = 99u; else r2 = 130u;
  s += r2;
  r3 = 1u; if (b < 14u) r3 = 2u; if (b < 14u) r3 = 9u;
  s += r3;
  if (a == 17u) r3 = 114u; else r3 = 23u;
  s += r3;
  if (!(((a * a) & 3u) != 2u)) r0 = 85u; else r0 = 135u;
  s += r0;
  return s;
}

unsigned f194(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  r0 = 1u; if (b < 20u) r0 = 2u; if (b < 20u) r0 = 9u;
  s += r0;
  if (a < 5u) {
  i = 0u; do { i = i + 1u; s = s + i; } while (i < 2u);
  }
  if (a < 25u) {
  r3 = 1u; if (b < 10u) r3 = 2u; if (b < 10u) r3 = 9u;
  s += r3;
  }
  r3 = 1u; if (b < 9u) r3 = 2u; if (b < 9u) r3 = 9u;
  s += r3;
  return s;
}

unsigned f195(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  r3 = 73u;
  s += r3;
  if (a == 1u) r3 = 147u; else r3 = 8u;
  s += r3;
  if (b < 20u) {
  if (!(((b & a) <= a))) r1 = 94u; else r1 = 195u;
  s += r1;
  }
  if (b < 7u) {
  if (a < 17u) r1 = 98u; else r1 = 160u;
  s += r1;
  }
  return s;
}

unsigned f196(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  if (a < 12u) {
  if (a < 16u) r3 = 4u; else r3 = 158u;
  s += r3;
  }
  if (((a & b) <= b)) r0 = 145u; else r0 = 20u;
  s += r0;
  i = 0u; do { i = i + 1u; s = s + i; } while (i < 2u);
  r2 = 1u; if (b < 20u) r2 = 2u; if (b < 20u) r2 = 9u;
  s += r2;
  if (((a * (a + 1u)) & 1u) == 0u) r2 = 163u; else r2 = 16u;
  s += r2;
  return s;
}

unsigned f197(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  if (!(((a & b) <= b))) r2 = 58u; else r2 = 174u;
  s += r2;
  r0 = 1u; if (a < 14u) r0 = 2u; if (a < 14u) r0 = 9u;
  s += r0;
  r0 = 26u;
  s += r0;
  r3 = 95u;
  s += r3;
  if (b < 21u) {
  if (a == 0u) r0 = 173u; else r0 = 5u;
  s += r0;
  }
  if (a < 24u) {
  if (a < 23u) r1 = 62u; else r1 = 109u;
  s += r1;
  }
  if (a < 21u) {
  if (a == 13u) r0 = 139u; else r0 = 48u;
  s += r0;
  }
  return s;
}

unsigned f198(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  if (b < 25u) {
  if (b < 13u) r3 = 7u; else r3 = 109u;
  s += r3;
  }
  if (a < 22u) {
  if (((b * (b + 1u)) & 1u) == 0u) r2 = 117u; else r2 = 61u;
  s += r2;
  }
  if (((a & b) <= b)) r1 = 139u; else r1 = 51u;
  s += r1;
  r2 = 1u; if (a < 11u) r2 = 2u; if (a < 11u) r2 = 9u;
  s += r2;
  i = 0u; do { i = i + 1u; s = s + i; } while (i < 5u);
  if (a < 18u) {
  r3 = 1u; if (a < 11u) r3 = 2u; if (a < 11u) r3 = 9u;
  s += r3;
  }
  return s;
}

unsigned f199(unsigned a, unsigned b) {
  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;
  if (b < 9u) {
  if (a == 25u && b == 27u) r0 = 144u; else r0 = 11u;
  s += r0;
  }
  if (a == 10u && b == 6u) r0 = 171u; else r0 = 58u;
  s += r0;
  if (b < 7u) {
  r1 = 1u; if (a < 15u) r1 = 2u; if (a < 15u) r1 = 9u;
  s += r1;
  }
  if (!(((b & a) <= a))) r2 = 64u; else r2 = 110u;
  s += r2;
  if (b < 6u) {
  if (a < 7u) r1 = 13u; else r1 = 135u;
  s += r1;
  }
  if (b < 9u) {
  r0 = 95u;
  s += r0;
  }
  if (b < 25u) {
  r2 = 1u; if (b < 14u) r2 = 2u; if (b < 14u) r2 = 9u;
  s += r2;
  }
  r3 = 15u;
  s += r3;
  return s;
}
