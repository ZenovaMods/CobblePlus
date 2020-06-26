#pragma once

#include "Zenova.h"

class CobblePlus : public Zenova::Mod {
public:
	static std::string versionId;

private:
	virtual void Start();

	virtual ~CobblePlus() {}
	virtual void Update() {}
	virtual void Tick() {}
	virtual void Stop() {
		Zenova_Info("CobblePlus Stop");
	}
};