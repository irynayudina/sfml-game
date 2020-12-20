#include "MyGame.h"
//purple lines
//163, 73, 164 better
//light filling
//234, 189, 234
//****************************************************private functions
void MyGame::InitVariables()
{
	this->window = nullptr;
	this->enemySpawnTimerMax = 10.f;
	this->enemySpawnTimer = this->enemySpawnTimerMax;
	this->maxEnemies = 5;

	
	this->gap_between_environment_elements = 170;
	this->size_of_environment_elements = 80;
	this->padding = 85;
	this->background_color = new Color(0,0,0);
	this->objects_color = new Color(163, 73, 164);
	this->rows_of_env_elem = 3;
}
void MyGame::InitWindow()
{
	this->videoMode.height = 750;
	this->videoMode.width = 1500;
	this->window = new RenderWindow(this->videoMode, "Lesson 1", Style::Titlebar | Style::Close);
	this->window->setFramerateLimit(30);
}
void MyGame::initEnemies()
{
	this->enemy.setPosition(20.f, 20.f);
	this->enemy.setSize(Vector2f(100.f, 100.f));
	this->enemy.setScale(Vector2f(0.5f, 0.5f));
	this->enemy.setFillColor(Color::Cyan);
	this->enemy.setOutlineColor(Color(163, 73, 164));
	this->enemy.setOutlineThickness(4.f);
}
//****************************************************constructors
MyGame::MyGame() 
{
	this->InitVariables();
	this->InitWindow();
	this->initCircle();
	this->initTriangle();
	this->initEnemies();
}
MyGame::~MyGame() 
{
	delete this->window;
}



//****************************************************accessors
const bool MyGame::running() const
{
	return this->window->isOpen();
}



//****************************************************functions
void MyGame::pollEvents()
{
	while (this->window->pollEvent(this->ev))
	{
		switch (this->ev.type) {
		case Event::Closed:
			this->window->close();
			break;
		case Event::KeyPressed:
			if (ev.key.code == Keyboard::Escape) {
				this->window->close();
			}
		}
		
	}
}

void MyGame::uppdateMousePositions()
{
	/*
	uppdates the mouse position
	mouse position relative to window(vector2i)
	

	*/
	this->mousePosWindow = Mouse::getPosition(*this->window);
	this->mousePosView = this->window->mapPixelToCoords(this->mousePosWindow);
	std::cout << "Mouse position: " << this->mousePosWindow.x << " " << this->mousePosWindow.y << "\n";
}

void MyGame::spawnEnemy()
{
	/*
		spawn enemies and set their colors and positions
		sets a random position
		sets a random color
		adds enemy to the vector
	*/
	this->enemy.setPosition(static_cast<float>(rand() % static_cast<int>(this->window->getSize().x - this->enemy.getSize().x)),
							static_cast<float>(rand() % static_cast<int>(this->window->getSize().y - this->enemy.getSize().y)));
	this->enemy.setFillColor(Color::Green);
	//spawn the enemy
	this->enemies.push_back(this->enemy);

	//remove enemies at the end of screen
}

void MyGame::uppdateEnemies()
{
	/*
	uppdates the enmy spawn timer and spawns the enemy
	when total amount of enemies is less than the max
	moves enemies downwords
	removes the enemies from the age of the screen TODO
	*/
	if (this->enemies.size() < this->maxEnemies) {
		if (this->enemySpawnTimer >= this->enemySpawnTimerMax) {
			this->spawnEnemy();
			this->enemySpawnTimer = 0.f;
		}
		else this->enemySpawnTimer += 1.f;
	}
	//move the enemies
	/*for (auto& e : this->enemies) {
		e.move(0.f, 5.f);
	}*/
	for (int i = 0; i < this->enemies.size(); i++){
		bool deleted = false;
		this->enemies[i].move(0.f, 5.f);
		//check if clicked
		if (Mouse::isButtonPressed(Mouse::Left)) {
			if (this->enemies[i].getGlobalBounds().contains(this->mousePosView)) {
				this->enemies.erase(this->enemies.begin() + i);
			}
		}
		//if the enemy has passed the bottom of the window, delete the enemy
		if (this->enemies[i].getPosition().y > this->window->getSize().y) {
			deleted = true;
		}
		if (deleted) {

			this->enemies.erase(this->enemies.begin() + i);
		}
	}
}

void MyGame::renderEnemies()
{
	//rendering all the enemies
	for (auto& e : this->enemies) {
		this->window->draw(e);
	}
}

void MyGame::uppdate()
{
	this->pollEvents();
	this->uppdateMousePositions();
	this->initCircles();
	this->initTriangles();
	this->uppdateEnemies();
	//update mouse position
	//relative to the screen
	//std::cout << "Mouse position: " << Mouse::getPosition().x << " " << Mouse::getPosition().y << "\n";
	//relative to the window
	//std::cout << "Mouse position: " << Mouse::getPosition(*this->window).x << " " << Mouse::getPosition(*this->window).y << "\n";
}
void MyGame::render()
{
	/*
	* clear old frame
	* render objects
	* display frame in window
	renders the game objects
	*/
	this->window->clear(Color(126, 40, 127, 255));
	
	//draw here
	this->draw_circles();
	this->draw_triangles();
	this->renderEnemies();

	this->window->display();
}

void MyGame::initTriangle()
{
	this->tr = new MyEnvironmentTriangle(80.f, *this->background_color, *this->objects_color);
}
void MyGame::initTriangles()
{
	for (int i = 0; i < pow(this->rows_of_env_elem, 2); i++) {
		int c = 0;
		int r = 0;
		c = ceil(i / this->rows_of_env_elem);
		c % 2 ? r = 1 : r = 0;
		float xpos;
		float ypos;
		xpos = this->padding + r * (this->gap_between_environment_elements + this->size_of_environment_elements) + (i % this->rows_of_env_elem) * (this->gap_between_environment_elements + this->size_of_environment_elements);
		ypos = this->padding + c * (this->gap_between_environment_elements + this->size_of_environment_elements);
		this->tr->SetPosition(xpos, ypos);
		this->tr->changeColor(*this->objects_color);
		this->environment_triangles.insert(this->environment_triangles.end(), *this->tr);
	}
	//delete this->tr;
}

void MyGame::draw_triangles()
{
	for(auto & t : this->environment_triangles) {
		t.DRAW(this->window);
	}
}

void MyGame::initCircle()
{
	this->cir = new MyEnvironmentCircle(80.f, *this->background_color, *this->objects_color);
}

void MyGame::initCircles()
{
	
	for (int i = 0; i < pow(this->rows_of_env_elem, 2); i++) {
		int c = 0;
		int r = 0;
		c = ceil(i / this->rows_of_env_elem);
		c % 2 ? r = 0 : r = 1;
		float xpos;
		float ypos;
		xpos = this->padding + r * (this->gap_between_environment_elements + this->size_of_environment_elements) + (i % this->rows_of_env_elem) * (this->gap_between_environment_elements + this->size_of_environment_elements) + this->size_of_environment_elements;
		ypos = this->padding + c * (this->gap_between_environment_elements + this->size_of_environment_elements) + this->size_of_environment_elements;
		this->cir = new MyEnvironmentCircle(80.f, *this->background_color, *this->objects_color);
		this->cir->SetPosition(xpos, ypos);
		this->cir->changeColor(*this->objects_color);
		//ypos = this->padding + c * (this->gap_between_environment_elements + this->size_of_environment_elements) + this->size_of_environment_elements;
		this->environment_circles.insert(this->environment_circles.end(), *this->cir);
	}
}


void MyGame::draw_circles()
{
	for (auto& t : this->environment_circles) {
		t.DRAW(this->window);
	}
}
