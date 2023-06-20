#pragma once

#include "Vector.h"

namespace Engine::Rendering
{
    class Camera final
    {
    public:
        void Set() const;

    public:
        Vector<2> Location = { 0.0f, 0.0f };
        Vector<2> Sight    = { 0.0f, 0.0f };
        float     Angle    = { 0.0f };
    };

    namespace Text
    {
        class Component final
        {
        public:
            void Render();

        public:
            char const * Text = nullptr;

            struct
            {
                char const * Name       = nullptr;
                int          Size       = 0;
                bool         Bold       = false;
                bool         Italic     = false;
                bool         Underlined = false;
                bool         StructOut  = false;
            }
            Font;

            struct
            {
                unsigned char Red   = 0;
                unsigned char Green = 0;
                unsigned char Blue  = 0;
            }
            Color;

        public:
            Vector<2> Location = { 0.0f, 0.0f };
            Vector<2> Length   = { 0.0f, 0.0f };
            float     Angle    = { 0.0f };
        };
    }

    namespace Image
    {
        class Component final
        {
        public:
            void Render();

        public:
            char const * Name = nullptr;

        public:
            Vector<2> Location = { 0.0f, 0.0f };
            Vector<2> Length   = { 0.0f, 0.0f };
            float     Angle    = { 0.0f };
        };
    }

    namespace Animation
    {
        class Component final
        {
        public:
            void Render();

        public:
            char const * Name       = nullptr;
            float        Playback   = 0.0f; //애니메이션 컴포넌트의 재생 위치 => 특정 프레임 표시
            float        Duration   = 0.0f; //일정한 시간 간격 나타냄 => 애니메이션이 얼마나 실행되는 지
            bool         Repeatable = false; //반복 가능한지 여부
            bool         Flipped    = false; //뒤집혀 있는지 여부

        public:
            Vector<2> Location = { 0.0f, 0.0f };
            Vector<2> Length   = { 0.0f, 0.0f };
            float     Angle    = { 0.0f };
        };
    }
}