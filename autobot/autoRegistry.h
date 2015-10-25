#pragma once

#include <iostream>

using namespace System;

ref class autoRegistry
{
public:
	autoRegistry(void);
	int monitorKey(String ^ key);
};
