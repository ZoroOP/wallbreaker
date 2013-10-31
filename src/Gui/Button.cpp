#include "Button.hpp"
#include "Theme.hpp"


using namespace gui;

Button::Button(const sf::String& string, int id):
	Widget(id),
	m_box(BitmapText(Theme::getFont()))
{
	m_box.item().setColor(Theme::TEXT_COLOR);
	m_box.setSize(Theme::WIDGET_WIDTH, Theme::getBaseLine());
	setString(string);
	setSize(m_box.getSize());
}


void Button::setString(const sf::String& string)
{
	m_box.item().setString(string);
	m_box.adjustItem();

}


const sf::String& Button::getString() const
{
	return m_box.item().getString();
}


void Button::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	target.draw(m_box, states);
}

// callbacks -------------------------------------------------------------------

void Button::onStateChanged(State state)
{
	m_box.applyState(state);
}


void Button::onMouseMoved(float, float)
{
	if (isFocused() && sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		m_box.press();
	}
}


void Button::onMousePressed(float, float)
{
	m_box.press();
}


void Button::onMouseReleased(float x, float y)
{
	m_box.release();
	if (containsPoint({x, y}))
	{
		triggerCallback();
	}
}


void Button::onKeyPressed(sf::Keyboard::Key key)
{
	if (key == sf::Keyboard::Return)
	{
		triggerCallback();
		m_box.press();
	}
}


void Button::onKeyReleased(sf::Keyboard::Key key)
{
	if (key == sf::Keyboard::Return)
	{
		m_box.release();
	}
}

