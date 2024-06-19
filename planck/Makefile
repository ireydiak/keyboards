KEYMAP_DIR=../qmk_firmware/keyboards/planck/keymaps/ireydiak

.PHONY: build
build: link
	qmk compile -kb planck/rev7 -km ireydiak

.PHONY: link
link: unlink
	ln -sf "$(realpath ireydiak)" "${KEYMAP_DIR}"

.PHONY: unlink
unlink:
	rm -rf  "${KEYMAP_DIR}"
