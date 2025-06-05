/* SPDX-License-Identifier: GPL-3.0-or-later */
/****************************************

---
Copyright (C) 2025~2025 David SPORN
---
This is part of **Micro-controller devices**.
A C++ abstraction layer to model devices linked to a micro-controller.
****************************************/

// ================[BEGIN typical specialization]==================
enum ConcreteError { READ_ERROR, NOT_READABLE };
class ConcreteInputDevice final
    : public cmspk::ucdev::InputValueDevice<uint8_t, ConcreteError> {
public:
  virtual ~ConcreteInputDevice() {}
  ConcreteInputDevice() : value(0), readable(true), readSuccess(true) {}

  ConcreteInputDevice *whenValueIs(uint8_t v) noexcept {
    value = v;
    return this;
  }
  ConcreteInputDevice *whenReadableIs(bool v) noexcept {
    readable = v;
    return this;
  }
  ConcreteInputDevice *whenReadSuccessIs(bool v) noexcept {
    readSuccess = v;
    return this;
  }

private:
  uint8_t value;
  bool readable;
  bool readSuccess;

  virtual std::expected<void, ConcreteError> checkReadability() noexcept {
    if (readable) {
      return std::expected<void, ConcreteError>();
    } else {
      return std::unexpected(ConcreteError::NOT_READABLE);
    }
  }

  virtual std::expected<uint8_t, ConcreteError> doRead() noexcept {
    if (readSuccess) {
      return value;
    } else {
      return std::unexpected(ConcreteError::READ_ERROR);
    }
  }
};
// ================[END typical specialization]==================

Test(InputValueDevice, read_must_fail_when_check_readability_fails) {
  ConcreteInputDevice d;

  // prepare
  d.whenReadableIs(false);

  // execute
  auto result = d.read();

  // verify
  cr_assert_not(result);
  cr_assert_eq(result.error(), ConcreteError::NOT_READABLE);
}

Test(InputValueDevice, read_must_fail_when_actual_read_fails) {
  ConcreteInputDevice d;

  // prepare
  d.whenReadSuccessIs(false);

  // execute
  auto result = d.read();

  // verify
  cr_assert_not(result);
  cr_assert_eq(result.error(), ConcreteError::READ_ERROR);
}

Test(InputValueDevice, read_must_succeed_when_all_is_well) {
  ConcreteInputDevice d;

  // prepare
  d.whenValueIs(42);

  // execute
  auto result = d.read();

  // verify
  cr_assert(result);
  cr_assert_eq(result.value(), 42);
}
