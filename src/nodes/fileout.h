#ifndef FILEOUT_H
#define FILEOUT_H

#include <flow.h>
#include <node.h>
#include <QFile>
#include <QTextStream>

CD3_DECLARE_NODE(FileOut)
public:
	FileOut();
	virtual ~FileOut();
	void init(ptime start, ptime end, int dt);
	int f(ptime time, int dt);
	void deinit();
private:
	Flow in;
	string out_file_name;
	QFile file;
	QTextStream stream;
};

#endif // FILEOUT_H
