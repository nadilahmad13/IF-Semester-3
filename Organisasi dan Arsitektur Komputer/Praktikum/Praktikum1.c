#include <stdio.h>

// gura - hitung x|y dengan ~ dan &
// Contoh : gura(6,5) = 7
// Legal ops : ~ &
// Max ops : 5
// Rating : 1
int gura(int x, int y){
    return ~(~x & ~y);
}

// rushia - Berikan nilai terkecil dalam two's complement
// Legal ops : ! ~ & ^ | + << >>
// Max ops : 4
// Rating : 1
int rushia(void){
    return 1<<31;
}

// kobokan - hitung sisa dari x jika dibagi 2 pangkat n
// Contoh : kobokan(100,5) = 4
// Semu input bernilai positif dan keluaran harus positif
// Legal ops : ~ & ! + << >>
// Max ops : 5
// Rating : 2
unsigned int kobokan(unsigned int x, int n){
    return x & ((1<<n) + ~0);
}

// fauna - Mengembalikan byte ke-n dari word x
// Byte dirutkan dari 0 (LSB) ke 3 (MSB)
// Contoh : fauna(0x12345678,1) = 0x56
// Legal ops : ! ~ & ^ | + << >>
// Max ops : 6
// Rating : 2
int fauna(int x, int n){
    return (x >> (n << 3)) & 0xFF;
}

// yamada - Periksa apakah x berada diantara 135 dan 182 inklusif
// Contoh : yamada(182) = 1
//          yamada(1000) = 0
//          yamada(140) = 1
// Legal Ops : ! ~ & ^ | + << >>
// Max ops : 12
// Rating : 3
int yamada(int x){
    return !((x + ~135 + 1) >> 31) & !((182 + ~x + 1) >> 31);
}

// pekora - balik urutan byte pada x
// Contoh ; pekora(0x01020304) = 0x04030201
// Legal ops : ! ~ & ^ | + << >>
// Max ops : 25
// Rating : 3
int pekora(int x){
    int a = x & 0xFF;
    int b = (x >> (1<<3)) & 0xFF;
    int c = (x >> (2<<3)) & 0xFF;
    int d = (x >> (3<<3)) & 0xFF;
    int ret = d | (c << 8);
    ret = ret | (b << 16);
    ret = ret | (a << 24);
    return ret;
}

// mumei - geser x kekanan dengan aturan logical shift
// asumsikan 0 <= n <= 31
// contoh : mumei(0x87654321,4) = 0x08765432
// Legal ops : ! ~ & ^ | + << >>
// Max ops : 20
// Rating : 3
int mumei(int x, int n){
    int a = x >> n;
    int b = (1 << 31) >> n;
    int c = b << 1;
    return a & ~c;
}

// moona - hitung banyak bit nol dari kanan (trailing zeroes) dalam representasi 32 bit nilai x
// Anda diperbolehkan menggunakan konstanta besar pada soal ini
// Contoh : moona(128) = 7
//          moona(-2) = 1
//          moona(57) = 0
//          moona(24) = 3
//          moona(0) = 32
// Legal ops : ! ~ & ^ | + << >>
// Max ops : 50
// Rating : 4
int moona(int x){
    int y;
    int z;
    y = x & (x + ~1 + 1);
    z = x ^ y;
    z = z + ~1 + 1;
    z = (z & (0x55555555)) + ((z >> 1) & (0x55555555));
    z = (z & (0x33333333)) + ((z >> 2) & (0x33333333));
    z = (z & (0x0f0f0f0f)) + ((z >> 4) & (0x0f0f0f0f));
    z = (z & (0x00ff00ff)) + ((z >> 8) & (0x00ff00ff));
    z = (z & (0x0000ffff)) + ((z >> 16) & (0x0000ffff));
    return z;
}

// ollie - hitung sisa dari a jika dibagi 30
// contoh ollie(100) = 10
// Legal ops : ! ~ & ^ | + << >>
// Max ops : 40
// Rating : 4
unsigned int ollie(unsigned int a){
    unsigned int b,c,d,e,f;
    b = a >> 2;
    b = b + (b >> 4);
    b = b + (b >> 8);
    b = b + (b >> 16);
    d = b >> 3;
    c = a + 1 + ~((d << 5) + ~(d << 1) + 1);
    e = c + ~29;
    f = !((e >> 31) & 1);
    return c + ~((f << 5) + ~(f << 1) + 1) + 1;   
}

// coco - Hitung 2*f untuk f floating point f
// argumen f dan hasil merupakan representasi bit dari bilangan desimal
// dalam bentuk single-precision floating point
// jika f NaN, kembalikan f
// Legal ops : Semua operasi integer/unsigned termasuk ||, &&. juga if, while
// Max ops : 30
// Rating : 4
unsigned coco(unsigned uf){
    // sign = a
    // exp = b
    // ufexp = c
    int a,b,c, isZero;
    a = uf & (0x80 << 24);
    b = (0x7F << 24) | (0x80 << 16);
    c = uf & b;
    isZero = !c;
    if (isZero){
        uf = (uf << 1) | a;
    }
    else if (c != b){
        uf += (1<<23);
    }
    return uf;
}