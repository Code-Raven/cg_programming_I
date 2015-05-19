#include "World.h"

//TODO: Add functionality later...
World::World(){
	plane = new Plane(1, 1);

	//load world...
	ifstream myfile(LEVEL_0);

	char buffer[256];
	char* path = ;

	if (myfile.is_open())
	{
		string line;
		unsigned char len = 0;

		while ( getline (myfile,line) )
		{
			line.copy(buffer, len = line.length());
			buffer[len] = '\0';

			if(buffer[0] == 35){
				//TODO: get next count...
				//count = buffer[1];
				continue;
			}

			if(buffer[0] > 47 && buffer[0] < 58){
				//TODO: add level data...
				continue;
			}
			
			if(buffer[0] == 32 || buffer[0] == '\0'){
				//Empty line...
				continue;
			}

			unsigned char commaLen = FindChar(buffer, ',');

			//Found textures...
			if(commaLen > 0){
				strcpy(path, buffer);
				path[commaLen - 1] = '\0';
				continue;
			}

			//load textures...
			//string filePath = 
		}

		myfile.close();
	}

	else cout << "Unable to open file"; 
}

unsigned char World::FindChar(const char* buffer, const char& c){
	//TODO: Search for char c, if found return true...
	char* value = (char*)buffer;
	unsigned char len = 0;

	while(value != '\0'){
		++len;
		if(*value == c){
			return len;
		}
		++value;
	}

	return len = 0;
}

//TODO: Add functionality later...
World::~World(){
	delete plane;
	plane = NULL;
}

void World::Update(const float& deltaTime){

	plane->Update(deltaTime);
}

void World::Render(const Camera& camera){
	plane->Render(camera);
}