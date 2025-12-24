int main(void) { // 정수형을 리턴 값으로 갖는 함수
    int a; // 변수 선언
    int b;
    b = Watt(a); // main calls Watt first
    b = Volt(a, b); // then calls volt
}

int Watt(int a) {
    int w;
    w = Volt(w, 10); //Watt calls Volt
    return w;
}

int Volt(int q, int r) {
    int k;
    int m;
    return k;
}