#pragma once
template <class T>
void select(T* a, int n) {
	int i, j, c;
	T t;
	bool exchange = false;
	for (i = 0; i < n - 1; i++) {
		exchange = 0;
		t = a[i];
		for (j = i + 1; j < n; j++) {
			if (a[j] < t) {
				exchange = 1;
				c = j;
				t = a[j];
			}
		}
		if (exchange) {
			a[c] = a[i];
			a[i] = t;
		}
	}
}
template <class T>
void insert(T* a, int n) {
	int i, j;
	T t;
	for (int i = 1; i < n; i++) {
		t = a[i];
		for (j = i - 1; j >= 0 && t < a[j]; j--) a[j + 1] = a[j];
		a[j + 1] = t;
	}
}

template <class T>
void boobleSort(T* a, int n) {
    int flag = 1;
    T t;
    while (flag) {
        flag = 0;
        for (int i = 0; i < n - 1; i++) {
            if (a[i + 1] < a[i]) {
                t = a[i]; a[i] = a[i + 1]; a[i + 1] = t;
                flag = 1;
            }
        }
    }
}
template <class T>
void shell(T* a, int n) {
    int steps[5] = { 121,40,13,4,1 };
    int j;
    T t;
    for (int k = 0; k < 5; k++) {
        int step = steps[k];
        for (int i = step; i < n; i++) {
            t = a[i];
            for (j = i - step; j >= 0 && t < a[j]; j -= step)a[j + step] = a[j];
            a[j + step] = t;
        }
    }

}
template <class T>
void qs(T* a, int left, int right) {
    int i = left;
    int j = right;
    T x = a[(left + right) / 2];
    T t;
    do {
        while (i < right && a[i] < x)i++;
        while (j > left && a[j] > x)j--;
        if (i <= j) {
            t = a[i]; a[i] = a[j]; a[j] = t;
            i++; j--;
        }

    } while (i <= j);
    if (j > left)qs(a, left, j);
    if (i < right)qs(a, i, right);
}