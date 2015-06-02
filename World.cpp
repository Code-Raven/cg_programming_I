#include "World.h"

namespace{
	const u8 MAX_BUFFER_SIZE = 64;
	const u8 MAX_PATH_SIZE = 32;
}

//TODO: Add functionality later...
World::World(){
	plane = new Plane(1, 1);
	GLuint textureID = plane->LoadBMP("test.bmp");

	//load world...
	ifstream myfile(LEVEL_0);

	char buffer[::MAX_BUFFER_SIZE];
	char path[::MAX_PATH_SIZE];

	if (myfile.is_open())
	{
		string line;
		unsigned char len = 0;

		bool loadLevelData = true;

		while ( getline (myfile,line) )
		{
			line.copy(buffer, len = line.length());
			buffer[len] = '\0';

			if(IS_EMPTY_LINE(buffer[0])){
				continue;
			}
			else if(LOAD_TEXTURE(buffer[0])){
				//Setting buffer size...
				numTextures = ASCII_ZERO - buffer[1];
				textureBuffer = (char*)malloc(MAX_PATH_SIZE * numTextures);

				loadLevelData = false;
				continue;
			}
			else if(LOAD_LEVELDATA(buffer[0])){
				//Setting buffer size...
				levelWidth = ASCII_ZERO - buffer[1];
				levelHeight = ASCII_ZERO - buffer[3];
				levelBuffer = (char*)malloc(MAX_BUFFER_SIZE * levelWidth * levelHeight);

				loadLevelData = true;
				continue;
			}
			else if(loadLevelData){
				//TODO: Load level data here...
				continue;
			}

			unsigned char commaLen = FindChar(buffer, ',');

			//Found textures...
			if(commaLen > 0){
				//strcpy_s(path, commaLen, buffer);
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