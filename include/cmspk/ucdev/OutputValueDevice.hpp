/* SPDX-License-Identifier: GPL-3.0-or-later */
/****************************************

---
Copyright (C) 2025~2025 David SPORN
---
This is part of **Micro-controller devices**.
A C++ abstraction layer to model devices linked to a micro-controller.
****************************************/
#ifndef CMSPK__UCDEV__OUTPUT_VALUE_DEVICE__HPP
#define CMSPK__UCDEV__OUTPUT_VALUE_DEVICE__HPP

#include <expected>
namespace cmspk::ucdev {
// ================[ CODE BEGINS ]================
/**
 * An abstraction of a device giving access to a writable value.
 *
 * @param T storage type for the value, typically a scalar like `bool` or
 * `uint8_t`.
 * @param E representation type of an error.
 *
 * > This is part of **Micro-controller devices**.
 * >
 * > Copyright (C) 2025~2025 David SPORN
 * > **Licence** GPL 3.0 or later.
 */

template <typename T, typename E>
class OutputValueDevice {
  public:
    virtual ~OutputValueDevice() noexcept {}

    /**
     * Write operation.
     *
     * @returns the result of the write operation.
     */
    std::expected<void, E> write(T value) noexcept {
        return checkWritability().and_then([this, value]() { return doWrite(value); });
    }

  private:
    /**
     * Extension point to implement the check performed before trying the write
     * operation.
     *
     * @returns the result of the check.
     */
    virtual std::expected<void, E> checkWritability() noexcept = 0;

    /**
     * Extension point to implement the actual write operation.
     *
     * @returns the result of the write operation.
     */
    virtual std::expected<void, E> doWrite(T value) noexcept = 0;
};

// ================[ END OF CODE ]================
}  // namespace cmspk::ucdev
#endif
