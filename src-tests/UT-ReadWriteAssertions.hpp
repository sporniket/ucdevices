/* SPDX-License-Identifier: GPL-3.0-or-later */
/****************************************

---
Copyright (C) 2025~2025 David SPORN
---
This is part of **Micro-controller devices**.
A C++ abstraction layer to model devices linked to a micro-controller.
****************************************/

// ================[BEGIN typical override]==================

class TypicalEnabledReadableDevice : public cmspk::ucdev::ReadWriteAssertions {
public:
  virtual ~TypicalEnabledReadableDevice() {}

  virtual bool isReadable() const noexcept { return true; }
  virtual bool isNotReadable() const noexcept { return false; }

  virtual bool isEnabled() const noexcept { return true; }
  virtual bool isDisabled() const noexcept { return false; }
};

class TypicalEnabledWritableDevice : public cmspk::ucdev::ReadWriteAssertions {
public:
  virtual ~TypicalEnabledWritableDevice() {}

  virtual bool isWritable() const noexcept { return true; }
  virtual bool isNotWritable() const noexcept { return false; }

  virtual bool isEnabled() const noexcept { return true; }
  virtual bool isDisabled() const noexcept { return false; }
};

// ================[END typical override]==================

Test(ReadWriteAssertions, is_not_readable_by_default) {
  cmspk::ucdev::ReadWriteAssertions rwasserts;

  cr_assert(rwasserts.isNotReadable());
  cr_assert_not(rwasserts.isReadable());
}

Test(ReadWriteAssertions, is_not_writable_by_default) {
  cmspk::ucdev::ReadWriteAssertions rwasserts;

  cr_assert(rwasserts.isNotWritable());
  cr_assert_not(rwasserts.isWritable());
}

Test(ReadWriteAssertions, is_disabled_by_default) {
  cmspk::ucdev::ReadWriteAssertions rwasserts;

  cr_assert(rwasserts.isDisabled());
  cr_assert_not(rwasserts.isEnabled());
}

Test(ReadWriteAssertions, assertions_are_polymorphic) {
  TypicalEnabledReadableDevice readable;
  TypicalEnabledWritableDevice writable;
  cmspk::ucdev::ReadWriteAssertions *rwasserts;

  rwasserts = &readable;

  cr_assert(rwasserts->isReadable());
  cr_assert(rwasserts->isNotWritable());
  cr_assert(rwasserts->isEnabled());
  cr_assert_not(rwasserts->isNotReadable());
  cr_assert_not(rwasserts->isWritable());
  cr_assert_not(rwasserts->isDisabled());

  rwasserts = &writable;

  cr_assert(rwasserts->isNotReadable());
  cr_assert(rwasserts->isWritable());
  cr_assert(rwasserts->isEnabled());
  cr_assert_not(rwasserts->isReadable());
  cr_assert_not(rwasserts->isNotWritable());
  cr_assert_not(rwasserts->isDisabled());
}
