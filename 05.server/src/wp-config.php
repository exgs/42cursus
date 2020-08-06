<?php
/**
 * The base configuration for WordPress
 *
 * The wp-config.php creation script uses this file during the
 * installation. You don't have to use the web site, you can
 * copy this file to "wp-config.php" and fill in the values.
 *
 * This file contains the following configurations:
 *
 * * MySQL settings
 * * Secret keys
 * * Database table prefix
 * * ABSPATH
 *
 * @link https://wordpress.org/support/article/editing-wp-config-php/
 *
 * @package WordPress
 */

// ** MySQL settings - You can get this info from your web host ** //
/** The name of the database for WordPress */
define( 'DB_NAME', 'wordpress' );

/** MySQL database username */
define( 'DB_USER', 'yunslee' );

/** MySQL database password */
define( 'DB_PASSWORD', '1234' );

/** MySQL hostname */
define( 'DB_HOST', 'localhost' );

/** Database Charset to use in creating database tables. */
define( 'DB_CHARSET', 'utf8' );

/** The Database Collate type. Don't change this if in doubt. */
define( 'DB_COLLATE', '' );

/**#@+
 * Authentication Unique Keys and Salts.
 *
 * Change these to different unique phrases!
 * You can generate these using the {@link https://api.wordpress.org/secret-key/1.1/salt/ WordPress.org secret-key service}
 * You can change these at any point in time to invalidate all existing cookies. This will force all users to have to log in again.
 *
 * @since 2.6.0
 */
define('AUTH_KEY',         '.=;#v$?6rG}cP?yB~x59S01.V9z/!wI@=[xVf-H?:7ThJA`ke1rK!R((4sE4%6l^');
define('SECURE_AUTH_KEY',  'M+1;~gclcfw2:LNG/nYrx~.D{AnV&2jKo}D+YbHBc]gws$x@r*Ur8@dRavZ4Td(+');
define('LOGGED_IN_KEY',    'E=Qx|qc1n;~-&Oo3SH_`6^wPhqd?H4xlp|!BC&P1jU+0?[D#Kjn;YdXIZ}&Zq[B0');
define('NONCE_KEY',        '?T~kP|AW7g{MOhR6I1=QW--[;1q3/,Ok.3oz7yPr&4=6n2B|N|&O1+F4e]U.k-t+');
define('AUTH_SALT',        '_,2. 6m7i8wIg+dORPO1J +nmaRhTkMieG}-3,]uz>Us&>ik4H0+%rVDmT3Gwl]W');
define('SECURE_AUTH_SALT', 'q!H;u|.}Tpg6|h<T,;F48~-DWbOY )MFuJ0YJ~gmPZA9W|kE_>6&tP:KJ9g71,c[');
define('LOGGED_IN_SALT',   'q.jV:N>A$+;IR1Fr=dA+!>0mk+xonCsp4Rz$QU+xijIF}y3>ud^8t+B#L?G:gAw_');
define('NONCE_SALT',       '51Ur?w;auSzW=<-4B^s|WHAcQ|CJ=/cip#He+eyl9/,2]OsoqW|kICJmko2.%{X<');

/**#@-*/

/**
 * WordPress Database Table prefix.
 *
 * You can have multiple installations in one database if you give each
 * a unique prefix. Only numbers, letters, and underscores please!
 */
$table_prefix = 'wp_';

/**
 * For developers: WordPress debugging mode.
 *
 * Change this to true to enable the display of notices during development.
 * It is strongly recommended that plugin and theme developers use WP_DEBUG
 * in their development environments.
 *
 * For information on other constants that can be used for debugging,
 * visit the documentation.
 *
 * @link https://wordpress.org/support/article/debugging-in-wordpress/
 */
define( 'WP_DEBUG', false );

/* That's all, stop editing! Happy publishing. */

/** Absolute path to the WordPress directory. */
if ( ! defined( 'ABSPATH' ) ) {
	define( 'ABSPATH', __DIR__ . '/' );
}
/**  임시적으로 파일을 생성및 제거하는 폴더 */
define('WP_TEMP_DIR', dirname(__FILE__) . '/wp-content/temp/');

/** Sets up WordPress vars and included files. */
require_once ABSPATH . 'wp-settings.php';
