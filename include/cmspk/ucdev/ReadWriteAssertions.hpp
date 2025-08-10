/* SPDX-License-Identifier: GPL-3.0-or-later */
/****************************************

---
Copyright (C) 2025~2025 David SPORN
---
This is part of **Micro-controller devices**.
A C++ abstraction layer to model devices linked to a micro-controller.
****************************************/
#ifndef CMSPK__UCDEV__READ_WRITE_ASSERTIONS__HPP
#define CMSPK__UCDEV__READ_WRITE_ASSERTIONS__HPP

#include <expected>
namespace cmspk::ucdev {
// ================[ CODE BEGINS ]================
/**
 * A set of assertions about the read/write capabilities of a device.
 *
 * This implementation provides default assertions values so that subclasses
 * override only have to override some assertions of the set.
 *
 * > This is part of **Micro-controller devices**.
 * >
 * > Copyright (C) 2025~2025 David SPORN
 * > **Licence** GPL 3.0 or later.
 */

class ReadWriteAssertions {
public:
  virtual ~ReadWriteAssertions() noexcept {}

  /**
   * Asserts the readability of the pin.
   *
   * @returns `false`, always.
   */
  virtual bool isReadable() const noexcept { return false; }

  /**
   * Asserts the unreadability of the pin.
   *
   * @returns `true`, always.
   */
  virtual bool isNotReadable() const noexcept { return true; }

  /**
   * Asserts the writability of the pin.
   *
   * @returns `false`, always.
   */
  virtual bool isWritable() const noexcept { return false; }

  /**
   * Asserts the unwritability of the pin.
   *
   * @returns `true`, always.
   */
  virtual bool isNotWritable() const noexcept { return true; }

  /**
   * Asserts the enabling of the pin.
   *
   * @returns `false`, always.
   */
  virtual bool isEnabled() const noexcept { return false; }

  /**
   * Asserts the disabling of the pin.
   *
   * @returns `true`, always.
   */
  virtual bool isDisabled() const noexcept { return true; }
};

// ================[ END OF CODE ]================
} // namespace cmspk::ucdev
#endif
