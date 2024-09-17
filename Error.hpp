#pragma once

#include <string>

static bool hadError = false;

void Report(int line, const std::string& where, const std::string& message);
void Error(int line, const std::string& message);