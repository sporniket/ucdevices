/* SPDX-License-Identifier: GPL-3.0-or-later */
/****************************************

---
Copyright (C) 2025~2025 David SPORN
---
This is part of **Micro-controller devices**.
A C++ abstraction layer to model devices linked to a micro-controller.
****************************************/

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
