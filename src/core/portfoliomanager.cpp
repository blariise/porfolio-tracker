#include <iostream>

#include "portfoliomanager.h"

PortfolioManager::PortfolioManager() {}

void PortfolioManager::addPortfolio(std::unique_ptr<Portfolio> portfolio) {
  m_portfolios.emplace_back(std::move(portfolio));
}

void PortfolioManager::removePortfolio(std::size_t portfolio_index) {
  if (portfolio_index < std::size(m_portfolios)) {
    auto portfolio { m_portfolios.begin() + portfolio_index };
    m_portfolios.erase(portfolio, portfolio + 1);
  }
}

double PortfolioManager::getTotalValue() const {
  double value { 0 };
  for (const auto& portfolio : m_portfolios)
    value += portfolio->getTotalValue();
  return value;
}

void PortfolioManager::print() const {
  for (const auto& portfolio : m_portfolios)
    std::cout << portfolio->getName() << '\n'; 
}

Portfolio& PortfolioManager::getPortfolio(std::size_t portfolio_index) {
  return *m_portfolios.at(portfolio_index);
}
