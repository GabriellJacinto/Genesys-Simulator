/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   QueueableItem.cpp
 * Author: rlcancian
 *
 * Created on 23 de abril de 2021, 15:09
 */

#include "QueueableItem.h"
#include "../../kernel/simulator/ModelDataDefinition.h"
#include "../../kernel/simulator/Model.h"
#include "../../kernel/simulator/Simulator.h"
#include <cassert>


std::string QueueableItem::convertEnumToStr(QueueableType type) {
	switch (static_cast<int> (type)) {
		case 0: return "QUEUE";
		case 1: return "SET";
		// case 2: return "HOLD";
	}
	return "Unknown";
}

QueueableItem::QueueableItem(ModelDataDefinition* queueOrSet, QueueableItem::QueueableType queueableType, std::string index) {
	_queueableType = queueableType;
	_queueOrSet = queueOrSet;
	_index = index;
}

QueueableItem::QueueableItem(Model* model, std::string queueName = "") {
	_queueableType = QueueableItem::QueueableType::QUEUE;
	ModelDataDefinition* data = model->getDataManager()->getDataDefinition(Util::TypeOf<Queue>(), queueName);
	if (data != nullptr) {
		_queueOrSet = dynamic_cast<Queue*> (data);
	} else {
		_queueOrSet = model->getParentSimulator()->getPluginManager()->newInstance<Queue>(model, queueName);
	}
	_index = "0";
    _queueableName = queueName;

    SimulationControlGeneric<std::string>* propIndex = new SimulationControlGeneric<std::string>(
                                        std::bind(&QueueableItem::getIndex, this), std::bind(&QueueableItem::setIndex, this, std::placeholders::_1),
                                        Util::TypeOf<QueueableItem>(), getName(), "Index", "");
	SimulationControlGenericClass<Queue*, Model*, Queue>* propQueue = new SimulationControlGenericClass<Queue*, Model*, Queue>(
										model,
										std::bind(&QueueableItem::getQueue, this), std::bind(&QueueableItem::setQueue, this, std::placeholders::_1),
										Util::TypeOf<QueueableItem>(), "", "Queue", "");
	SimulationControlGenericClass<Set*, Model*, Set>* propSet = new SimulationControlGenericClass<Set*, Model*, Set>(
										model,
										std::bind(&QueueableItem::getSet, this), std::bind(&QueueableItem::setSet, this, std::placeholders::_1),
										Util::TypeOf<QueueableItem>(), "", "Set", "");
	SimulationControlGenericEnum<QueueableItem::QueueableType, QueueableItem>* propType = new SimulationControlGenericEnum<QueueableItem::QueueableType, QueueableItem>(
										std::bind(&QueueableItem::getQueueableType, this),
										std::bind(&QueueableItem::setQueueableType, this, std::placeholders::_1),
										Util::TypeOf<QueueableItem>(), getName(), "QueueableType", "");

    model->getControls()->insert(propIndex);
	model->getControls()->insert(propQueue);
	model->getControls()->insert(propSet);
	model->getControls()->insert(propType);

    // setting properties
    _addProperty(propIndex);
	_addProperty(propQueue);
	_addProperty(propSet);
	_addProperty(propType);
}

bool QueueableItem::loadInstance(PersistenceRecord *fields) {
	bool res = true;
	try {
		_queueableType = static_cast<QueueableItem::QueueableType> (fields->loadField("queueableType", static_cast<int> (DEFAULT.queueableType)));
		_queueableName = fields->loadField("queueable", "");
		_index = fields->loadField("index", DEFAULT.index);
		if (_modeldataManager != nullptr) {
			if (_queueableType == QueueableItem::QueueableType::QUEUE) {
				_queueOrSet = _modeldataManager->getDataDefinition(Util::TypeOf<Queue>(), _queueableName);
			} else if (_queueableType == QueueableItem::QueueableType::SET) {
				_queueOrSet = _modeldataManager->getDataDefinition(Util::TypeOf<Queue>(), _queueableName);
			}
			if (_queueOrSet == nullptr) {
				auto model = _modeldataManager->getParentModel();
				_queueOrSet = model->getParentSimulator()->getPluginManager()->newInstance<Queue>(model, _queueableName);
			}
		}
		assert(_queueOrSet != nullptr);
	} catch (...) {
		res = false;
	}
	return res;
}

void QueueableItem::saveInstance(PersistenceRecord *fields, bool saveDefaultValues) {
	fields->saveField("queueableType", static_cast<int> (_queueableType), static_cast<int> (DEFAULT.queueableType), saveDefaultValues);
	fields->saveField("queueable", _queueOrSet->getName());
	fields->saveField("index", _index, DEFAULT.index, saveDefaultValues);
}

std::string QueueableItem::show() {
	return "queueType=" + std::to_string(static_cast<int> (_queueableType)) + ",queue=\"" + _queueOrSet->getName() + "\",index=\"" + _index + "\"";
}

void QueueableItem::_addProperty(PropertyBase* property) {
    _properties->insert(property);
}

List<PropertyBase*>* QueueableItem::getProperties() const {
    return _properties;
}

void QueueableItem::setIndex(std::string index) {
	this->_index = index;
}

std::string QueueableItem::getIndex() const {
	return _index;
}

std::string QueueableItem::getQueueableName() const {
	return _queueableName;
}

std::string QueueableItem::getName() const {
    return _queueableName;
}

void QueueableItem::setQueue(Queue* queue) {
	this->_queueOrSet = queue;
	_queueableName = queue->getName();
}

Queue* QueueableItem::getQueue() const {
	return static_cast<Queue*> (_queueOrSet);
}

void QueueableItem::setSet(Set* set) {
	this->_queueOrSet = set;
	_queueableName = set->getName();
}

Set* QueueableItem::getSet() const {
	return static_cast<Set*> (_queueOrSet);
}

void QueueableItem::setQueueableType(QueueableItem::QueueableType queueableType) {
	this->_queueableType = queueableType;
}

QueueableItem::QueueableType QueueableItem::getQueueableType() const {
	return _queueableType;
}

ModelDataDefinition* QueueableItem::getQueueable() const {
	return _queueOrSet;
}

void QueueableItem::setElementManager(ModelDataManager* modeldataManager) {
	_modeldataManager = modeldataManager;
}

//void QueueableItem::setComponentManager(ComponentManager* componentManager) {
//    this->_componentManager = componentManager;
//}
