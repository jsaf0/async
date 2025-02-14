// Copyright (c) 2023 Klemens D. Morgenstern
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <boost/async/main.hpp>
#include <boost/asio/steady_timer.hpp>

using namespace boost;

// tag::timer_example[]
async::main co_main(int argc, char * argv[]) // <1>
{
  asio::steady_timer tim{co_await asio::this_coro::executor, // <2>
                         std::chrono::milliseconds(std::stoi(argv[1]))}; // <3>
  co_await tim.async_wait(asio::deferred); // <4>
  co_return 0; // <5>
}
// end::timer_example[]
