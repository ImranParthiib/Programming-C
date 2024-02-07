#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <cmath>

class AbsoluteLayout {
public:
    void addLayoutComponent(std::string name, Component* comp) {
        throw std::invalid_argument("Function not implemented");
    }

    void removeLayoutComponent(Component* comp) {
        constraints.erase(comp);
    }

    Dimension preferredLayoutSize(Container* parent) {
        int maxWidth = 0;
        int maxHeight = 0;
        for (auto& constraint : constraints) {
            Component* comp = constraint.first;
            AbsoluteConstraints* ac = constraint.second;
            Dimension size = comp->getPreferredSize();

            int width = ac->getWidth();
            if (width == -1)
                width = size.getWidth();
            int height = ac->getHeight();
            if (height == -1)
                height = size.getHeight();

            if (ac->getX() + width > maxWidth)
                maxWidth = ac->getX() + width;
            if (ac->getY() + height > maxHeight)
                maxHeight = ac->getY() + height;
        }
        return Dimension(maxWidth, maxHeight);
    }

    Dimension minimumLayoutSize(Container* parent) {
        int maxWidth = 0;
        int maxHeight = 0;
        for (auto& constraint : constraints) {
            Component* comp = constraint.first;
            AbsoluteConstraints* ac = constraint.second;
            Dimension size = comp->getMinimumSize();

            int width = ac->getWidth();
            if (width == -1)
                width = size.getWidth();
            int height = ac->getHeight();
            if (height == -1)
                height = size.getHeight();

            if (ac->getX() + width > maxWidth)
                maxWidth = ac->getX() + width;
            if (ac->getY() + height > maxHeight)
                maxHeight = ac->getY() + height;
        }
        return Dimension(maxWidth, maxHeight);
    }

    void layoutContainer(Container* parent) {
        for (auto& constraint : constraints) {
            Component* comp = constraint.first;
            AbsoluteConstraints* ac = constraint.second;
            Dimension size = comp->getPreferredSize();
            int width = ac->getWidth();
            if (width == -1)
                width = size.getWidth();
            int height = ac->getHeight();
            if (height == -1)
                height = size.getHeight();

            comp->setBounds(ac->getX(), ac->getY(), width, height);
        }
    }

    void addLayoutComponent(Component* comp, AbsoluteConstraints* constr) {
        constraints[comp] = constr;
    }

    Dimension maximumLayoutSize(Container* target) {
        return Dimension(std::numeric_limits<int>::max(), std::numeric_limits<int>::max());
    }

    float getLayoutAlignmentX(Container* target) {
        return 0.0f;
    }

    float getLayoutAlignmentY(Container* target) {
        return 0.0f;
    }

    void invalidateLayout(Container* target) {}

private:
    std::map<Component*, AbsoluteConstraints*> constraints;
};

