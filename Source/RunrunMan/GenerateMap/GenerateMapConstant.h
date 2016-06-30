#pragma once

enum ObjectType {
	Empty = '0',
	DefaultCube = '1',
	//todo new Object type
};

struct sSpawnObject
{
	const char* CObject;
	//размер обьекта
	int x;
	int y;
	//начало отрисовки предмета
	int StartObject;

};



/*Тестовые объекты*/
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
const char CCube[] =
{
	ObjectType::Empty,
	ObjectType::Empty,
	ObjectType::Empty,
	ObjectType::DefaultCube,
	ObjectType::DefaultCube,
	ObjectType::DefaultCube,
	ObjectType::Empty,
	ObjectType::Empty,
	ObjectType::Empty,
};

const char CCube2[] =
{
	ObjectType::DefaultCube,
	ObjectType::DefaultCube,
	ObjectType::DefaultCube,
	ObjectType::DefaultCube,
	ObjectType::DefaultCube,
	ObjectType::DefaultCube,
	ObjectType::DefaultCube,
	ObjectType::DefaultCube,
	ObjectType::DefaultCube,
};

const char CCube3[] =
{
	ObjectType::DefaultCube, ObjectType::DefaultCube, ObjectType::DefaultCube, ObjectType::DefaultCube,
	ObjectType::DefaultCube, ObjectType::Empty, ObjectType::Empty, ObjectType::Empty,
	ObjectType::DefaultCube, ObjectType::Empty, ObjectType::Empty, ObjectType::Empty,
	ObjectType::DefaultCube, ObjectType::DefaultCube, ObjectType::DefaultCube, ObjectType::DefaultCube,
};

const char CClear[] =
{
	ObjectType::Empty,
};


const sSpawnObject OCube = { CCube, 1, 9, 3 };
const sSpawnObject OCube2 = { CCube2, 3, 3, 0 };
const sSpawnObject OCube3 = { CCube3, 4, 4, 0 };
const sSpawnObject OClear = { CClear, 1, 1, 0 };

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>