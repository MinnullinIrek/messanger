#pragma once

template <typedef Fn>
void RunWorkers(unsigned int n, const Fn& fn)
{
  n= std::max(1u, n);
  std::vector<std::jthread> workers;
  workers.reserve(n-1);
  while (--n) {
	workers.emplace_back(fn);
  }
  fn();
}

