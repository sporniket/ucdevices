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
 * This base class provides default assertions of never readable, never
 * writable, always disabled.
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
     * Asserts the readability of the pin, to be overriden to change the default
     * value.
     *
     * @returns `false`, always.
     */
    virtual bool isReadable() const noexcept { return false; }

    /**
     * Asserts the unreadability of the pin.
     *
     * @returns `true`, always.
     */
    bool isNotReadable() const noexcept { return !isReadable(); }

    /**
     * Asserts the writability of the pin, to be overriden to change the default
     * value.
     *
     * @returns `false`, always.
     */
    virtual bool isWritable() const noexcept { return false; }

    /**
     * Asserts the unwritability of the pin.
     *
     * @returns `true`, always.
     */
    bool isNotWritable() const noexcept { return !isWritable(); }

    /**
     * Asserts the enabling of the pin, to be overriden to change the default
     * value.
     *
     * @returns `false`, always.
     */
    virtual bool isEnabled() const noexcept { return false; }

    /**
     * Asserts the disabling of the pin.
     *
     * @returns `true`, always.
     */
    bool isDisabled() const noexcept { return !isEnabled(); }
};

/**
 * Override of ReadWriteAssertions for most readable devices : readable and
 * enabled.
 *
 * > This is part of **Micro-controller devices**.
 * >
 * > Copyright (C) 2025~2025 David SPORN
 * > **Licence** GPL 3.0 or later.
 */
class SimpleReadableDeviceAssertions : public ReadWriteAssertions {
  public:
    virtual ~SimpleReadableDeviceAssertions() {}

    virtual bool isReadable() const noexcept { return true; }

    virtual bool isEnabled() const noexcept { return true; }
};

/**
 * Override of ReadWriteAssertions for most writable devices : writable and
 * enabled.
 *
 * > This is part of **Micro-controller devices**.
 * >
 * > Copyright (C) 2025~2025 David SPORN
 * > **Licence** GPL 3.0 or later.
 */
class SimpleWritableDeviceAssertions : public ReadWriteAssertions {
  public:
    virtual ~SimpleWritableDeviceAssertions() {}

    virtual bool isWritable() const noexcept { return true; }

    virtual bool isEnabled() const noexcept { return true; }
};

// ================[ END OF CODE ]================
}  // namespace cmspk::ucdev
#endif
