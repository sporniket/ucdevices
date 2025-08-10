/* SPDX-License-Identifier: GPL-3.0-or-later */
/****************************************

---
Copyright (C) 2025~2025 David SPORN
---
This is part of **Micro-controller devices**.
A C++ abstraction layer to model devices linked to a micro-controller.
****************************************/

// ================[BEGIN typical specialization]==================
class ConcreteOutputDevice final : public cmspk::ucdev::OutputValueDevice<uint8_t, ConcreteError> {
  public:
    virtual ~ConcreteOutputDevice() {}
    ConcreteOutputDevice() : value(0), writable(true), writeSuccess(true) {}

    uint8_t getValue() const noexcept { return value; }

    ConcreteOutputDevice *whenWritableIs(bool v) noexcept {
        writable = v;
        return this;
    }
    ConcreteOutputDevice *whenWriteSuccessIs(bool v) noexcept {
        writeSuccess = v;
        return this;
    }

  private:
    uint8_t value;
    bool writable;
    bool writeSuccess;

    virtual std::expected<void, ConcreteError> checkWritability() noexcept {
        if (writable) {
            return std::expected<void, ConcreteError>();
        } else {
            return std::unexpected(ConcreteError::NOT_WRITABLE);
        }
    }

    virtual std::expected<void, ConcreteError> doWrite(uint8_t v) noexcept {
        if (writeSuccess) {
            value = v;
            return std::expected<void, ConcreteError>();
        } else {
            return std::unexpected(ConcreteError::WRITE_ERROR);
        }
    }
};
// ================[END typical specialization]==================

Test(OutputValueDevice, write_must_fail_when_check_writability_fails) {
    ConcreteOutputDevice d;

    // prepare
    cr_assert_eq(d.getValue(), 0);
    d.whenWritableIs(false);

    // execute
    auto result = d.write(42);

    // verify
    cr_assert_not(result);
    cr_assert_eq(result.error(), ConcreteError::NOT_WRITABLE);
    cr_assert_eq(d.getValue(), 0);
}

Test(OutputValueDevice, write_must_fail_when_actual_write_fails) {
    ConcreteOutputDevice d;

    // prepare
    cr_assert_eq(d.getValue(), 0);
    d.whenWriteSuccessIs(false);

    // execute
    auto result = d.write(42);

    // verify
    cr_assert_not(result);
    cr_assert_eq(result.error(), ConcreteError::WRITE_ERROR);
    cr_assert_eq(d.getValue(), 0);
}

Test(OutputValueDevice, write_must_succeed_when_all_is_well) {
    ConcreteOutputDevice d;

    // prepare
    cr_assert_eq(d.getValue(), 0);

    // execute
    auto result = d.write(42);

    // verify
    cr_assert(result);
    cr_assert_eq(d.getValue(), 42);
}
