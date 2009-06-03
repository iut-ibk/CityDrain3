#ifndef SIMULATIONREGISTRY_H
#define SIMULATIONREGISTRY_H

#include <map>
#include <string>
#include <cd3globals.h>

class ISimulationFactory;
class ISimulation;

typedef std::map<std::string, const ISimulationFactory *> sim_reg_type;

class CD3_PUBLIC SimulationRegistry
{
public:
	SimulationRegistry();
	virtual ~SimulationRegistry();
	void addSimulationFactory(const ISimulationFactory *factory);
	void addPlugin(const std::string plugin_path);
	bool contains(const std::string &name) const;
	ISimulation *createSimulation(const std::string &name) const;
private:
	sim_reg_type registry;
};

typedef void (*regSimFunProto)(SimulationRegistry *reg);

#endif // SIMULATIONREGISTRY_H
