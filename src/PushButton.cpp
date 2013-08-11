#include <legui/PushButton.h>
#include <legui/Config.h>

namespace legui
{
    PushButton::PushButton(Container *parent)
        : Clickable(parent), Frame(parent)
    {
        m_label = new Label(parent);
    }
    PushButton::~PushButton()
    {
        delete m_label;
    }

    void PushButton::onUpdate(float frametime)
    {
        Frame::onUpdate(frametime);
        Clickable::onUpdate(frametime);
        m_label->onUpdate(frametime);
    }
    bool PushButton::onEvent(const sf::Event &e)
    {
        bool block = false;
        block = Clickable::onEvent(e);
        if(!block)
            block = Frame::onEvent(e);
        if(!block)
            block = m_label->onEvent(e);
        return block;
    }
    void PushButton::setBoundingBox(const sf::FloatRect &box)
    {
        Frame::setBoundingBox(box);
        Clickable::setBoundingBox(box);
        sf::FloatRect middle = box;
        middle.left = box.left + box.width / 2 - m_label->getBoundingBox().width / 2;
        middle.top = box.top + box.height / - m_label->getBoundingBox().height / 2;
        m_label->setBoundingBox(middle);
    }
    void PushButton::updateSize()
    {
        //Nothing to do
        //Size keeps the same all the time.
    }
    void PushButton::draw(sf::RenderTarget &target, sf::RenderStates states) const
    {
        Frame::draw(target, states);
        target.draw(*m_label, states);
    }
    Label* PushButton::getLabel()
    {
        return m_label;
    }

    void PushButton::D_onFocusGained()
    {
        this->setOutlineColor(Config::getColor("BUTTON_OUTLINE_FOCUSED"));
    }
    void PushButton::D_onFocusLost()
    {
        this->setOutlineColor(Config::getColor("BUTTON_OUTLINE"));
    }
    void PushButton::D_onHoverGained()
    {
        this->setFillColor(Config::getColor("BUTTON_FILL_HOVER"));
    }
    void PushButton::D_onHoverLost()
    {
        this->setFillColor(Config::getColor("BUTTON_FILL"));
    }
}
