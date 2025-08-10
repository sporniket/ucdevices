/* SPDX-License-Identifier: GPL-3.0-or-later */
/****************************************

---
Copyright (C) 2025~2025 David SPORN
---
This is part of **Micro-controller devices**.
A C++ abstraction layer to model devices linked to a micro-controller.
****************************************/
#ifndef CMSPK__UCDEV__INPUT_VALUE_DEVICE__HPP
#define CMSPK__UCDEV__INPUT_VALUE_DEVICE__HPP

#include <expected>
namespace cmspk::ucdev {
// ================[ CODE BEGINS ]================
/**
 * An abstraction of a device giving access to a readable value.
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
class InputValueDevice {
  public:
    virtual ~InputValueDevice() noexcept {}

    /**
     * Read operation.
     *
     * @returns the result of the read operation.
     */
    std::expected<T, E> read() noexcept {
        return checkReadability().and_then([this]() { return doRead(); });
    }

  private:
    /**
     * Extension point to implement the check performed before trying the read
     * operation.
     *
     * @returns the result of the check.
     */
    virtual std::expected<void, E> checkReadability() noexcept = 0;

    /**
     * Extension point to implement the actual read operation.
     *
     * @returns the result of the read operation.
     */
    virtual std::expected<T, E> doRead() noexcept = 0;
};

// ================[ END OF CODE ]================
}  // namespace cmspk::ucdev
#endif
