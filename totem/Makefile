KEYMAP_DIR=../qmk_firmware/keyboards/totem/keymaps/ireydiak

.PHONY: build
build: link
	qmk compile -kb totem -km ireydiak

.PHONY: link
link: unlink
	ln -sf "$(realpath ireydiak)" "${KEYMAP_DIR}"

.PHONY: unlink
unlink:
	rm -rf  "${KEYMAP_DIR}"

.PHONY: clone
clone:
	git clone https://github.com/GEIGEIGEIST/qmk-config-totem.git "../qmk_firmware/keyboards/totem"
	mv ../qmk_firmware/keyboards/totem/totem/* ../qmk_firmware/keyboards/totem
