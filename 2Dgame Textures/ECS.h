#pragma once
#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <bitset>
#include <array>
//https://www.youtube.com/watch?v=cY1S7-Ka6n0&ab_channel=tori on loop
class Component;
class Entity;

//ID for ai and other components

using ComponentID = std::size_t;

inline ComponentID getComponentTypeID()
{
	//store the component ID
	//everytime we call last id we'll always remember what it was last
	static ComponentID lastID = 0;

	//everytime we call we get the next one
	//like 1 2 3 and so on
	return lastID++;
}

//we create a template function for component id
//so when we paste in a component we got so itll be assigned 1 
//so we want it to give back the same id rather than 1 2 3 4 

template <typename T> inline ComponentID getComponentTypeID() noexcept
{
	//generates a last id to put back on our typeID
	static ComponentID typeID = getComponentTypeID();

		return typeID;
}

//we want to tell if the entity has a component attached
//mathematical components that an entity can hold
constexpr std::size_t maxComponents = 32;

//if matches sync we know we got components
using ComponentBitSet = std::bitset<maxComponents>;
//array of component pointers
using ComponentArray = std::array<Component*, maxComponents>;

//base class for our components
class Component
{
public:
	Entity* entity;

	virtual void init() {}
	virtual void update() {}
	virtual void draw () {}

	virtual ~Component() {}
};

//entity

class Entity
{
private:
	//bool so we can track if entity is active
	//if false we remove him from the game
	bool active = true;

	//vectors?
	//think of it as an array but dynamic in size 
	//list of components
	std::vector<std::unique_ptr<Component>> components;

	ComponentArray componentArray;
	ComponentBitSet componentBitSet;

	//we use functions to access this

public:
	//update function
	void update()
	{
		//make entity loop through all components
		//for every components in components we can update and draw it
		for (auto& c : components) c->update();
		
	}
	void draw() 
	{
		for (auto& c : components) c->draw();
	}
	bool isActive() const { return active; }

	//destroy any given components when that loop sthrough  new entity
	void destroy() { active = false; }

	//has components our bitset
	template <typename T> bool hasComponent() const
	{
		return componentBitSet[getComponentTypeID<T>()];
	}

	//next we want to create a new template
	template<typename T, typename... TArgs>
	T& addComponent(TArgs&&... mArgs)
	{
		T* c(new T(std::forward<TArgs>(mArgs)...));
		c->entity = this;
		std::unique_ptr<Component> uPtr{ c };
		components.emplace_back(std::move(uPtr));

		componentArray[getComponentTypeID<T>()] = c;
		componentBitSet[getComponentTypeID<T>()] = true;

		c->init();
		return *c;
	}
	template<typename T> T& getComponent() const
	{
		auto ptr(componentArray[getComponentTypeID<T>()]);
		return *static_cast<T*>(ptr);
	}
};

//list of all our entities
class Manager
{
private:
	std::vector<std::unique_ptr<Entity>> entities;

public:
	void update()
	{
		for (auto& e : entities) e->update();
	}
	void draw()
	{
		for (auto& e : entities) e->draw();
	}
	void refresh()
	{
		entities.erase(std::remove_if(std::begin(entities), std::end(entities),
			[](const std::unique_ptr<Entity>& mEntity)
			{
				return !mEntity->isActive();
			}),
			std::end(entities));
	}
	Entity& addEntity()
	{
		Entity* e = new Entity();
		std::unique_ptr<Entity> uPtr{ e };
		entities.emplace_back(std::move(uPtr));
		return *e;
	}
};





