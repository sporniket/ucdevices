/* SPDX-License-Identifier: GPL-3.0-or-later */
/****************************************

---
Copyright (C) 2025~2025 David SPORN
---
This is part of **Micro-controller devices**.
A C++ abstraction layer to model devices linked to a micro-controller.
****************************************/

// standard libs
#include <cstdint>

// testing framework
#include <criterion/criterion.h>

// project
#include "cmspk/ucdev.hpp"

// ================[BEGIN common code]==================
enum ConcreteError { READ_ERROR, NOT_READABLE, WRITE_ERROR, NOT_WRITABLE };
// ================[END common code]==================

// test suites
#include "UT-InputValueDevice.hpp"
#include "UT-OutputValueDevice.hpp"
