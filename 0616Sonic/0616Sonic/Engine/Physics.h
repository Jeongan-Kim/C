#pragma once

namespace Engine::Physics
{
    template<typename Shape>
    class Component final : public Shape
    {
    public:
        Component();
        Component(Shape const &);

        template<typename Shape>
        [[nodiscard]] bool Collide(Component<Shape> const &) const;
    };

    //Test.cpp
}

/*
    충돌체의 종류
    - circle, point, quadrangle
*/