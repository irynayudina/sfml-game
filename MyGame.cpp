#include "MyGame.h"
//****************************************************private functions
void MyGame::InitVariables()
{
	this->window = nullptr;
	this->enemySpawnTimerMax = 10.f;////////////////////////////////////////////////////////////////////////////
	this->enemySpawnTimer = this->enemySpawnTimerMax;//////////////////////////////////////////////////////////
	this->maxEnemies = 5;//////////////////////////////////////////////////////////////////////////////////////

	
	this->gap_between_environment_elements = 100;
	this->size_of_environment_elements = 60;
	this->padding = 25;
	this->background_color = new Color(0,0,0);
	this->objects_color = new Color(163, 73, 164);
	this->rows_of_env_elem = 3;
}
void MyGame::InitWindow()
{
	this->videoMode.height = 900;
	this->videoMode.width = 1900;
	this->window = new RenderWindow(this->videoMode, "Lesson 1", Style::Titlebar | Style::Close);
	this->window->setFramerateLimit(30);
}
void MyGame::initEnemies()////////////////////////////////////////////////////////////////////////////////////////////////////
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
	this->initColorButton();
	this->initControlButton();
	this->init_main_char();
	this->placeChar();
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
	this->mousePosWindow = Mouse::getPosition(*this->window);
	this->mousePosView = this->window->mapPixelToCoords(this->mousePosWindow);
	std::cout << "Mouse position: " << this->mousePosWindow.x << " " << this->mousePosWindow.y << "\n";
}

void MyGame::spawnEnemy()/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
{
	this->enemy.setPosition(static_cast<float>(rand() % static_cast<int>(this->window->getSize().x - this->enemy.getSize().x)),
							static_cast<float>(rand() % static_cast<int>(this->window->getSize().y - this->enemy.getSize().y)));
	this->enemy.setFillColor(Color::Green);
	this->enemies.push_back(this->enemy);
}

void MyGame::uppdateEnemies()/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
{
	if (this->enemies.size() < this->maxEnemies) {
		if (this->enemySpawnTimer >= this->enemySpawnTimerMax) {
			this->spawnEnemy();
			this->enemySpawnTimer = 0.f;
		}
		else this->enemySpawnTimer += 1.f;
	}
	for (int i = 0; i < this->enemies.size(); i++){
		bool deleted = false;
		this->enemies[i].move(0.f, 5.f);
		/*if (Mouse::isButtonPressed(Mouse::Left)) {
			if (this->enemies[i].getGlobalBounds().contains(this->mousePosView)) {
				this->enemies.erase(this->enemies.begin() + i);
			}
		}*/
		if (this->enemies[i].getPosition().y > this->window->getSize().y) {
			deleted = true;
		}
		if (deleted) {

			this->enemies.erase(this->enemies.begin() + i);
		}
	}
}

void MyGame::renderEnemies()////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
{
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
	this->initColorButtons();
	this->initControlButtons();
	this->moveChar();
	this->deformChar();
	this->uppdateEnemies();////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	this->makeText();
	this->makeText_color();
}
void MyGame::render()
{
	this->window->clear(Color::Black);
	//draw here
	
	this->draw_circles();
	this->draw_triangles();
	this->drawChar();
	this->renderEnemies();///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	this->drawColorButtons();
	this->drawControlButtons();
	this->drawText();
	this->drawText_color();
	this->drawText_start();
	this->drawText_stop();
	this->drawText_restart();

	this->window->display();
}

void MyGame::initTriangle()
{
	this->tr = new MyEnvironmentTriangle(this->size_of_environment_elements, *this->background_color, *this->objects_color);
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
		xpos = this->padding + r * (this->gap_between_environment_elements + (this->size_of_environment_elements*2)) + (i % this->rows_of_env_elem) * (this->gap_between_environment_elements*2 + this->size_of_environment_elements*4);
		ypos = this->padding + c * (this->gap_between_environment_elements + this->size_of_environment_elements);
		this->tr = new MyEnvironmentTriangle(this->size_of_environment_elements, *this->background_color, *this->objects_color);
		this->tr->SetPosition(xpos, ypos);
		this->tr->changeColor(*this->objects_color);
		environment_triangles[i] = *this->tr;
	}
}

void MyGame::draw_triangles()
{
	for(auto & t : this->environment_triangles) {
		t.DRAW(this->window);
	}
}

void MyGame::initCircle()
{
	this->cir = new MyEnvironmentCircle(this->size_of_environment_elements, *this->objects_color, *this->objects_color);
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
		xpos = this->padding + r * (this->gap_between_environment_elements + (this->size_of_environment_elements * 2)) + (i % this->rows_of_env_elem) * (this->gap_between_environment_elements * 2 + this->size_of_environment_elements * 4);
		ypos = this->padding + c * (this->gap_between_environment_elements + this->size_of_environment_elements);
		this->cir = new MyEnvironmentCircle(this->size_of_environment_elements, *this->background_color , *this->objects_color);
		this->cir->SetPosition(xpos, ypos);
		this->cir->changeColor(*this->objects_color);
		environment_circles[i] = *this->cir;
	}
}


void MyGame::draw_circles()
{
	for (auto& t : this->environment_circles) {
		t.DRAW(this->window);
	}
}

void MyGame::initColorButton()
{
	this->colorb = new MyButton(100, 30, Color(255, 174, 201), *this->background_color);
}

void MyGame::initColorButtons()
{
	for (int i = 0; i < 5; i++) {
		float xpos;
		float ypos;
		xpos = this->padding + i * 130;
		ypos = 650;
		this->colorb = new MyButton(100, 30, Color(255, 174, 201), *this->background_color);
		this->colorb->SetPosition(xpos, ypos);
		switch (i)
		{
		case 0:
			this->colorb->ChangeColor(Color(163, 73, 164));
			break;
		case 1:
			this->colorb->ChangeColor(Color(128, 39, 248));
			break;
		case 2:
			this->colorb->ChangeColor(Color(218, 3, 197));
			break;
		case 3:
			this->colorb->ChangeColor(Color(255, 19, 96));
			break;
		case 4:
			this->colorb->ChangeColor(Color(234, 189, 234));
			break;
		}
		color_buttons[i] = *this->colorb;
	}
}

void MyGame::drawColorButtons()
{
	for (auto& t : this->color_buttons) {
		t.DRAW(this->window);
	}
}

void MyGame::initControlButton()
{
	this->controlb = new MyButton(200, 75, Color(255, 174, 201), *this->background_color);
}

void MyGame::initControlButtons()
{
	for (int i = 0; i < 3; i++) {
		float xpos;
		float ypos;
		xpos = this->padding + i * 275;
		ypos = 750;
		this->controlb = new MyButton(200, 75, Color(255, 174, 201), *this->background_color);
		this->controlb->SetPosition(xpos, ypos);
		switch (i)
		{
		case 0:
			makeText_start(xpos+10, ypos);
			break;
		case 1:
			makeText_stop(xpos+10, ypos);
			break;
		case 2:
			makeText_restart(xpos+10, ypos);
			break;
		}
		this->control_buttons[i] = *this->controlb;

	}
}

void MyGame::drawControlButtons()
{
	for (auto& t : this->control_buttons) {
		t.DRAW(this->window);
	}
}

void MyGame::makeText()
{
	if (!this->font.loadFromFile("Sansation-LightItalic.ttf"))//Pacifico
	{

		throw("file was not loaded");
		// error...
	}
	text.setFont(font); // font is a sf::Font

   // set the string to display
	text.setString("left-click on any point within the \nprogram window, \nthis will set moving trajectory \nof the character\n");

	// set the character size
	text.setCharacterSize(32); // in pixels, not points!

	// set the color
	text.setFillColor(Color(163, 73, 164));

	// set the text style
	//text.setStyle(sf::Text::Bold | sf::Text::Underlined);
	text.setPosition((this->padding + (this->rows_of_env_elem) * (this->gap_between_environment_elements * 2 + this->size_of_environment_elements * 4)), this->padding);
}

void MyGame::drawText()
{
	window->draw(text);
}

void MyGame::makeText_start(float x, float y)
{
	if (!this->font.loadFromFile("Sansation-LightItalic.ttf"))//Pacifico
	{

		throw("file was not loaded");
		// error...
	}
	text_start.setFont(font); // font is a sf::Font

   // set the string to display
	text_start.setString("start");

	// set the character size
	text_start.setCharacterSize(32); // in pixels, not points!

	// set the color
	text_start.setFillColor(Color(163, 73, 164));

	// set the text style
	//text_start.setStyle(sf::Text::Bold | sf::Text::Underlined);
	text_start.setPosition(x, y);
}

void MyGame::drawText_start()
{
	window->draw(text_start);
}

void MyGame::makeText_stop(float x, float y)
{
	if (!this->font.loadFromFile("Sansation-LightItalic.ttf"))
	{

		throw("file was not loaded");
		// error...
	}
	text_stop.setFont(font); // font is a sf::Font

   // set the string to display
	text_stop.setString("stop");

	// set the character size
	text_stop.setCharacterSize(32); // in pixels, not points!

	// set the color
	text_stop.setFillColor(Color(163, 73, 164));

	// set the text style
	//text_stop.setStyle(sf::Text::Bold | sf::Text::Underlined);
	text_stop.setPosition(x, y);
}

void MyGame::drawText_stop()
{
	window->draw(text_stop);
}

void MyGame::makeText_restart(float x, float y)
{
	if (!this->font.loadFromFile("Sansation-LightItalic.ttf"))
	{

		throw("file was not loaded");
		// error...
	}
	text_restart.setFont(font); // font is a sf::Font

   // set the string to display
	text_restart.setString("restart");

	// set the character size
	text_restart.setCharacterSize(32); // in pixels, not points!

	// set the color
	text_restart.setFillColor(Color(163, 73, 164));

	// set the text style
	//text_restart.setStyle(sf::Text::Bold | sf::Text::Underlined);
	text_restart.setPosition(x, y);
}

void MyGame::drawText_restart()
{
	window->draw(text_restart);
}

void MyGame::makeText_color()
{
	if (!this->font.loadFromFile("Sansation-LightItalic.ttf"))
	{

		throw("file was not loaded");
		// error...
	}
	text_color.setFont(font); // font is a sf::Font

   // set the string to display
	text_color.setString("change the color of the main character");

	// set the character size
	text_color.setCharacterSize(32); // in pixels, not points!

	// set the color
	text_color.setFillColor(Color(163, 73, 164));

	// set the text style
	//text_color.setStyle(sf::Text::Bold | sf::Text::Underlined);
	text_color.setPosition(this->padding, (this->gap_between_environment_elements + this->size_of_environment_elements)*4- this->size_of_environment_elements);
}

void MyGame::drawText_color()
{
	window->draw(text_color);
}

void MyGame::change_color_onclick()
{
	for (int i = 0; i < 5; i++) {
		if (Mouse::isButtonPressed(Mouse::Left)) {
			if (this->color_buttons->outer_rectangle->rectangle->getGlobalBounds().contains(this->mousePosView)) {
				this->changeColor(this->color_buttons[i].getColor());
				
			}
	}

	
}

void MyGame::init_main_char()
{
	character = new MyCharacter(40, 40, *this->objects_color);
	character_reserved = this->character;
}

void MyGame::placeChar()
{
	character->SetPosition(200, 200);
}

void MyGame::moveChar()
{
}

void MyGame::deformChar()
{
}

void MyGame::drawChar()
{
	this->character->DRAW(this->window);
}

void MyGame::restart()
{
	this->character = this->character_reserved;
}

void MyGame::stop()
{
	stopped = true;
}

void MyGame::start()
{
	stopped = false;
}

void MyGame::changeColor(Color col)
{
	this->character->changeColor(col);
}


