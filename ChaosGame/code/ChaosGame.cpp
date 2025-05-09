// Include important C++ libraries here
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <sstream>
#include <vector>

//Make the code easier to type with "using namespace"
using namespace sf;
using namespace std;

int main()
{
	// Create a video mode object
	VideoMode vm(1920, 1080);
	// Create and open a window for the game
	RenderWindow window(vm, "Chaos Game!!", Style::Default);
	
	vector<Vector2f> vertices;
	vector<Vector2f> points;


    Font font;
	Text text;
	text.setFont(font);
	text.setPosition(0, 0);

    if (!font.loadFromFile("Arial.ttf")) // Ensure "arial.ttf" is in the same directory
    {
        return -1;
    }
	
	text.setString("Click 3 points");
	text.setCharacterSize(24); 
	text.setFillColor(Color::Green);
	


	while (window.isOpen())
	{
		/*
		****************************************
		Handle the players input
		****************************************
		*/
		Event event;
		while (window.pollEvent(event))
		{
		    if (event.type == Event::Closed)
		    {
					// Quit the game when the window is closed
					window.close();
		    }
		    if (event.type == sf::Event::MouseButtonPressed)
		    {
			if (event.mouseButton.button == sf::Mouse::Left)
			{
			    std::cout << "the left button was pressed" << std::endl;
			    std::cout << "mouse x: " << event.mouseButton.x << std::endl;
			    std::cout << "mouse y: " << event.mouseButton.y << std::endl;
	
			    if(vertices.size() < 3)
			    {
				vertices.push_back(Vector2f(event.mouseButton.x, event.mouseButton.y));
			    }
			    else if(points.size() == 0)
			    {
				///fourth click
				///push back to points vector

				points.push_back(Vector2f(event.mouseButton.x, event.mouseButton.y));

			    }
			}
		    }
		}
		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			window.close();
		}
		/*
		****************************************
		Update
		****************************************
		*/
	
		if(points.size() > 0)
		{
		    ///generate more point(s)
		    ///select random vertex
		    ///calculate midpoint between random vertex and the last point in the vector
		    ///push back the newly generated coord.



			for (int i = 0; i < 10000; i++) 
            {
                int randomVertex = rand() % vertices.size();
                Vector2f lastPoint = points.back();
                Vector2f midpoint(
                    (lastPoint.x + vertices[randomVertex].x) / 2,
                    (lastPoint.y + vertices[randomVertex].y) / 2);
                points.push_back(midpoint);
				
            } 

		}
	
		/*
		****************************************
		Draw
		****************************************
		*/
		window.clear();
		for(int i = 0; i < static_cast<int>(vertices.size()); i++)
		{
		    RectangleShape rect(Vector2f(10,10));
		    rect.setPosition(Vector2f(vertices[i].x, vertices[i].y));
		    rect.setFillColor(Color::Blue);
		    window.draw(rect);
		}

		for(int i = 0; i < static_cast<int>(points.size()); i++)
		{
			RectangleShape rect(Vector2f(2,2)); //smaller size
		    rect.setPosition(Vector2f(points[i].x, points[i].y));
		    rect.setFillColor(Color::Red);
		    window.draw(rect);
		}
		



		window.draw(text);

		window.display();
	
	}
	
}
