int atoi(const char *str) {
	// IMPORTANT: Please reset any member data you declared, as
	// the same Solution instance will be reused for each test case.
	if (str == NULL || str[0] == '\0') return 0;
	int neg = 0;
	char *p = (char *)str;
	while (*p == ' ') p++;
	if (!(isdigit(*p) || *p == '-' || *p == '+'))
		return 0;
	if (*p == '+')
		p++;
	if (*p == '-')
	{
		neg = 1;
		p++;
	}
	long long sum = 0;
	while (isdigit(*p))
	{
		sum = 10*sum + (*p - '0');
		if ((!neg && sum > INT_MAX) || (neg && sum > 2147483648))
		{
			return neg ? INT_MIN : INT_MAX;
		}
		p++;
	}
	return neg ? -sum : sum;
}