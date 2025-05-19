#pragma once

#include <spdlog/fmt/bundled/core.h>
#include "Events/Event.h"

template <>
struct fmt::formatter<ME::Event> : fmt::formatter<std::string> {
    auto format(const ME::Event& e, fmt::format_context& ctx) const -> decltype(ctx.out()) {
        return fmt::formatter<std::string>::format(e.ToString(), ctx);
    }
};

