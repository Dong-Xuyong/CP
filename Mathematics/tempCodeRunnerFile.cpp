int Test;
	cin >> Test;
	while (Test--) {
		int n;
		cin >> n;
		LL res = 1;
		LL a = 2;
		for (; n; n >>= 1) {
			if (n & 1) res = res * a % MOD;
			a = a * a % MOD;
		}
		res = (res - 1 + MOD) % MOD;
		cout << res << endl;
	}