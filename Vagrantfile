# -*- mode: ruby -*-
# vi: set ft=ruby :

VAGRANTFILE_API_VERSION = "2"

Vagrant.configure(VAGRANTFILE_API_VERSION) do |config|
  config.vm.box = "ubuntu/bionic64"
  config.vm.define "FunctionalProgrammingInCpp"
  config.vm.synced_folder ".", "/home/vagrant/repos/FPiCpp"
  config.vm.synced_folder "../dotfiles", "/home/vagrant/repos/dotfiles"
end
