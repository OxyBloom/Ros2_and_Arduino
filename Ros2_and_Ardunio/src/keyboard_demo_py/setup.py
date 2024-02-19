from setuptools import find_packages, setup

package_name = 'keyboard_demo_py'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='david',
    maintainer_email='esugamopah@gmail.com',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            "teleop_keyboard = keyboard_demo_py.teleop_keyboard:main",
            "simple_serial_transmitter = keyboard_demo_py.simple_serial_transmitter:main"
        ],
    },
)
