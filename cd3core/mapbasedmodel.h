#ifndef MAPBASEMODEL_H
#define MAPBASEMODEL_H

#include "model.h"

#include <boost/unordered/unordered_map.hpp>
#include <set>
#include <cd3globals.h>

typedef unordered_map<Node *, vector<NodeConnection *> > connection_type;


class CD3_PUBLIC MapBasedModel : public IModel
{
public:
	MapBasedModel();
	~MapBasedModel();

	string serialize() { //TODO implement
		return "";
	}

	void deserialize(const string &serialid) { //TODO implement
		(void) serialid;
	}

	void addNode(const string &name, Node *node);
	void addConnection(const string &src_node,
					   const string &src_port,
					   const string &sin_node,
					   const string &sin_port);


	//call before adding Connections
	void initNodes(const SimulationParameters &);

	node_set_type getSourceNodes();
	node_set_type getSinkNodes();

	vector<next_node_type> forward(Node *n);
	vector<next_node_type> backward(Node *n);

	vector<NodeConnection *> forwardConnection(Node *n);
	vector<NodeConnection *> backwardConnection(Node *n);

	const node_set_type *getNodes() const;

	name_node_map getNamesAndNodes() const;

	Node *getNode(const string &name) const;
	string getNodeName(const Node *name) const;
	con_count_type getForwardCounts() const;
	con_count_type getBackwardCounts() const;
	bool connected() const;
	void checkModel() const;

private:
	node_set_type all_nodes;
	node_set_type sink_nodes;
	node_set_type source_nodes;
	node_set_type uncon_nodes;
	name_node_map names_nodes;
	connection_type fwd_connections;
	connection_type bwd_connections;

};

#endif // MAPBASEMODEL_H
