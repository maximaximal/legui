#include <legui/PushButton.h>
#include <legui/Config.h>

namespace legui
{
    PushButton::PushButton(Container *parent)
        : Clickable(parent)
    {
        m_label = new Label(parent);
        m_frame = new Frame(parent);
        m_frame->setOutlineColor(Config::getColor("BUTTON_OUTLINE"));
        m_frame->setFillColor(Config::getColor("BUTTON_FILL"));
        m_frame->setOutlineThickness(Config::getFloat("BUTTON_OUTLINE_THICKNESS"));
    }
    PushButton::~PushButton()
    {
        delete m_label;
        delete m_frame;
    }

    void PushButton::onUpdate(float frametime)
    {
        Clickable::onUpdate(frametime);
        m_frame->onUpdate(frametime);
        m_label->onUpdate(frametime);
    }
    bool PushButton::onEvent(const sf::Event &e)
    {
        bool block = false;
        block = Clickable::onEvent(e);
        if(!block)
            block = m_frame->onEvent(e);
        if(!block)
            block = m_label->onEvent(e);
        return block;
    }
    void PushButton::setBoundingBox(const sf::FloatRect &box)
    {
        Clickable::setBoundingBox(box);
        m_frame->setBoundingBox(box);
        m_label->setCharacterSize((unsigned int) box.height - 10);
        m_label->setBoundingBox(sf::FloatRect(m_boundingBox.left + m_boundingBox.width / 2 - m_label->getBoundingBox().width / 2, 
                    m_boundingBox.top + m_boundingBox.height / 2 - m_label->getBoundingBox().height / 2,
                    m_label->getBoundingBox().width, m_label->getBoundingBox().height));
    }
    void PushButton::updateSize()
    {
        Clickable::updateSize();
        m_label->updateSize();
        m_frame->updateSize();
    }
    void PushButton::draw(sf::RenderTarget &target, sf::RenderStates states) const
    {
        target.draw(*m_frame, states);
        target.draw(*m_label, states);
    }
    Label* PushButton::getLabel()
    {
        return m_label;
    }
    Frame* PushButton::getFrame()
    {
        return m_frame;
    }

    void PushButton::D_onFocusGained()
    {
        m_frame->setOutlineColor(Config::getColor("BUTTON_OUTLINE_FOCUSED"));
    }
    void PushButton::D_onFocusLost()
    {
        m_frame->setOutlineColor(Config::getColor("BUTTON_OUTLINE"));
    }
    void PushButton::D_onHoverGained()
    {
        m_frame->setFillColor(Config::getColor("BUTTON_FILL_HOVER"));
    }
    void PushButton::D_onHoverLost()
    {
        m_frame->setFillColor(Config::getColor("BUTTON_FILL"));
    }
}
