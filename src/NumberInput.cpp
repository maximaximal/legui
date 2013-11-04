#include <legui/NumberInput.h>
#include <string>
#include <iostream>

using namespace std;

namespace legui
{
    NumberInput::NumberInput(Container *parent)
        : Clickable(parent)
    {
        m_numberInput = new legui::LineEdit();
        m_numberInput->setString("0");
    }
    NumberInput::~NumberInput()
    {
        delete m_numberInput;
    }
    void NumberInput::onUpdate(float frametime)
    {
        Clickable::onUpdate(frametime);
        if(m_numberInput->hasChanged())
        {
            m_onChanged(getValue());
        }
        m_numberInput->onUpdate(frametime);
    }
    bool NumberInput::onEvent(const sf::Event &e)
    {
        bool block = false;
        if(e.type == sf::Event::MouseWheelMoved)
        {
            if(m_boundingBox.contains(e.mouseWheel.x, e.mouseWheel.y))
            {
                int value = atoi(m_numberInput->getString().toAnsiString().c_str());
                value += e.mouseWheel.delta;
                m_numberInput->setString(to_string(value));
                m_onChanged(value);
            }
        }
        if(!block)
            block = m_numberInput->onEvent(e);
        if(!block)
            block = Clickable::onEvent(e);
        return block;
    }
    void NumberInput::setBoundingBox(const sf::FloatRect &box)
    {
        Clickable::setBoundingBox(box);
        sf::FloatRect smallBox;
        smallBox = box;
        smallBox.width -= box.width / 4;
        m_numberInput->setBoundingBox(smallBox);
    }
    void NumberInput::updateSize()
    {
        Clickable::updateSize();
        m_numberInput->updateSize();
    }
    void NumberInput::D_onChanged(int newValue)
    {
        //To be derived.
    }
    void NumberInput::draw(sf::RenderTarget &target, sf::RenderStates states) const
    {
        target.draw(*m_numberInput, states);
    }
    int NumberInput::getValue()
    {
        int value = atoi(m_numberInput->getString().toAnsiString().c_str());
        return value;
    }
    Nano::signal<void(int)>& NumberInput::onChanged()
    {
        return m_onChanged;
    }
}
