#ifndef ARRAYPARAMTEST_H
#define ARRAYPARAMTEST_H

#include <node.h>
#include <flow.h>

#include <vector>
using namespace std;

CD3_DECLARE_NODE(ArrayParamTest)
public:
	ArrayParamTest();
	virtual ~ArrayParamTest();
	void init(ptime start, ptime end, int dt);
	int f(ptime time, int dt);

private:
	Flow out;
	double Qe;
	vector<double> C;
};

#endif // ARRAYPARAMTEST_H
