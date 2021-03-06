struct Matrix {
    long long** mat;
    int a, b;
    
    Matrix() { a = b = 0; }

    Matrix(int a, int b) {
        this->a = a, this->b = b;
        mat = new long long*[a];
        for (int i = 0; i < a; ++i) {
            mat[i] = new long long[b];
            for (int j = 0; j < b; ++j) mat[i][j] = 0;
        }
    }
    
    Matrix(vector<vector<int>> v) : Matrix(v.size(), v[0].size()) {
        for (int i = 0; i < a; ++i) for (int j = 0; j < b; ++j) mat[i][j] = v[i][j];
    }
    
    void print() {
        for (int i = 0; i < a; ++i) {
            for (int j = 0; j < b; ++j) cout << mat[i][j] << " ";
            cout << "\n";
        }
        cout << "------------\n";
    }
    
    Matrix operator+(const Matrix& m) {
        Matrix ret(a, b);
        for (int i = 0; i < a; ++i) for (int j = 0; j < b; ++j) ret.mat[i][j] = (mat[i][j] + m.mat[i][j]) % MOD;
        return ret;
    }
    
    Matrix operator*(const Matrix& m) {
        Matrix ret(a, m.b);
        for (int i = 0; i < a; ++i) for (int j = 0; j < b; ++j) for (int k = 0; k < m.b; ++k) 
            ret.mat[i][k] = (ret.mat[i][k] + mat[i][j] * m.mat[j][k] % MOD) % MOD;
        return ret;
    }

    Matrix operator^(ll pow) {
        Matrix ret(a, a), base(*this); 
        for (int i = 0; i < a; ++i) ret.mat[i][i] = 1;
        while (pow) {
            if (pow & 1) ret = ret * base;
            base = base * base;
            pow /= 2;
        }
        return ret;
    }
};
