#include "Menu.hpp"


Menu::Menu():
	m_hover(NULL)
{
}


Menu::~Menu()
{
	for (WidgetVector::iterator it = m_widgets.begin(); it != m_widgets.end(); ++it)
	{
		delete *it;
	}
}


bool Menu::onEvent(const sf::Event& event, int& id)
{
	switch (event.type)
	{
	case sf::Event::MouseMoved:
		for (WidgetVector::iterator it = m_widgets.begin(); it != m_widgets.end(); ++it)
		{
			Button* button = *it;
			if (button->containsPoint(event.mouseMove.x - button->getX(), event.mouseMove.y - button->getY()))
			{
				if (m_hover != button)
				{
					if (m_hover != NULL)
						m_hover->onMouseLeave();

					m_hover = button;
					button->onMouseEnter();
				}

				return false;
			}
		}
		if (m_hover != NULL)
		{
			m_hover->onMouseLeave();
			m_hover = NULL;
		}
		break;
	case sf::Event::MouseButtonPressed:
		break;
	case sf::Event::MouseButtonReleased:
		if (m_hover != NULL && m_hover->containsPoint(event.mouseButton.x - m_hover->getX(), event.mouseButton.y - m_hover->getY()))
		{
			id = m_hover->getID();
			return true;
		}
		break;
	default:
		break;
	}
	return false;
}


void Menu::setPosition(float x, float y)
{
	m_position.x = x;
	m_position.y = y;
}

void Menu::addButton(const sf::String& string, int id)
{
	Button* button = new Button(string, id);
	sf::Vector2f pos;
	if (!m_widgets.empty())
	{
		Button* last = m_widgets.back();
		pos.x = last->getPosition().x;
		pos.y = last->getPosition().y + last->getSize().y + 10;
	}
	else
	{
		pos = m_position;
	}
	button->setPosition(pos);
	m_widgets.push_back(button);
}


void Menu::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (WidgetVector::const_iterator it = m_widgets.begin(); it != m_widgets.end(); ++it)
	{
		const Button& button = **it;
		target.draw(button, states);
	}
}
